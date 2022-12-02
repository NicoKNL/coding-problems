from collections import defaultdict

HORIZONTAL = 0
VERTICAL = 1


class Spot:
    def __init__(self, x, y, length, direction):
        self.x = x
        self.y = y
        self.length = length
        self.direction = direction

    def __repr__(self):
        return f"({self.x},{self.y}) -> {str(self.length)} {'VER' if self.direction else 'HOR'}"


SPOTS = []
WORDS = defaultdict(list)

GRID = None


def collect_horizontal_spots():
    for r in range(len(GRID)):
        start = 0
        end = 0
        for c in range(len(GRID[r])):
            if GRID[r][c] == "#":
                if start != end:
                    SPOTS.append(Spot(start, r, end - start + 1, HORIZONTAL))
                start = c + 1
                end = c + 1
            else:
                end = c

        if start != end:
            SPOTS.append(Spot(start, r, end - start + 1, HORIZONTAL))


def collect_vertical_spots():
    for c in range(len(GRID[0])):
        start = 0
        end = 0
        for r in range(len(GRID)):
            if GRID[r][c] == "#":
                if start != end:
                    SPOTS.append(Spot(c, start, end - start + 1, VERTICAL))
                start = r + 1
                end = r + 1
            else:
                end = r

        if start != end:
            SPOTS.append(Spot(c, start, end - start + 1, VERTICAL))


def is_done():
    for r in range(len(GRID)):
        for c in range(len(GRID[r])):
            if GRID[r][c] == ".":
                return False

    return True


def fits(spot, word):
    r = spot.y
    c = spot.x

    for i in range(spot.length):
        if spot.direction == HORIZONTAL:
            if not (GRID[r][c + i] == "." or GRID[r][c + i] == word[i]):
                return False
        else:
            if not (GRID[r + i][c] == "." or GRID[r + i][c] == word[i]):
                return False

    return True


def get(spot):
    r = spot.y
    c = spot.x

    word = ""
    for i in range(spot.length):
        if spot.direction == HORIZONTAL:
            word += GRID[r][c + i]
        else:
            word += GRID[r + i][c]

    return word


def put(spot, word):
    r = spot.y
    c = spot.x

    for i in range(spot.length):
        if spot.direction == HORIZONTAL:
            GRID[r][c + i] = word[i]
        else:
            GRID[r + i][c] = word[i]


def dfs(spot):
    if spot >= len(SPOTS):
        return True

    for i, (used, w) in enumerate(WORDS[SPOTS[spot].length]):
        if used:
            continue

        if fits(SPOTS[spot], w):
            WORDS[SPOTS[spot].length][i][0] = True
            cur = get(SPOTS[spot])
            put(SPOTS[spot], w)
            found = dfs(spot + 1)
            if found:
                return True

            WORDS[SPOTS[spot].length][i][0] = False
            put(SPOTS[spot], cur)


if __name__ == "__main__":
    rows, cols = map(int, input().split())
    GRID = [list(input()) for _ in range(rows)]

    n = int(input())

    for _ in range(n):
        word = input()
        WORDS[len(word)].append([False, word])

    collect_horizontal_spots()
    collect_vertical_spots()

    SPOTS.sort(key=lambda x: x.length, reverse=True)
    SPOTS.sort(key=lambda x: len(WORDS[x.length]))

    dfs(0)

    for row in GRID:
        print("".join(row))
