import sys

# (row, column)
UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)

OFFSET_TO_AIM = {UP: "^", DOWN: "v", RIGHT: ">", LEFT: "<"}

EMPTY_SPACE_OFFSETS = {"^": UP, "v": DOWN, ">": RIGHT, "<": LEFT}  # "."

DIAG_UP_DOWN_OFFSETS = {"^": LEFT, "v": RIGHT, ">": DOWN, "<": UP}  # "\"

DIAG_DOWN_UP_OFFSETS = {"^": RIGHT, "v": LEFT, ">": UP, "<": DOWN}  # "/"

OFFSETS = {
    ".": EMPTY_SPACE_OFFSETS,
    "\\": DIAG_UP_DOWN_OFFSETS,
    "/": DIAG_DOWN_UP_OFFSETS,
}


def isInGrid(row: int, col: int) -> bool:
    return 0 <= row < ROWS and 0 <= col < COLS


def getNextStates(
    state: tuple[int, int, str], symbol: str
) -> list[tuple[int, int, str]]:
    row, col, aim = state

    if symbol == "|":
        if aim in [">", "<"]:
            return [*getNextStates(state, "/"), *getNextStates(state, "\\")]
        else:
            return getNextStates(state, ".")

    if symbol == "-":
        if aim in ["^", "v"]:
            return [*getNextStates(state, "/"), *getNextStates(state, "\\")]
        else:
            return getNextStates(state, ".")

    offset = OFFSETS[symbol][aim]
    next_aim = OFFSET_TO_AIM[offset]
    next_row = row + offset[0]
    next_col = col + offset[1]

    if isInGrid(next_row, next_col):
        return [(next_row, next_col, next_aim)]
    else:
        return []


def raycast() -> set[tuple[int, int, str]]:
    SEEN_STATES = set()  # State: (row, col, aim)
    Q = [(0, 0, ">")]
    i = 0
    while i < len(Q):
        state = Q[i]
        i += 1

        if state not in SEEN_STATES:
            SEEN_STATES.add(state)

            symbol = GRID[state[0]][state[1]]
            next_states = getNextStates(state, symbol)

            if next_states:
                Q.extend(next_states)

    return SEEN_STATES


def getUniquePositions(states: set[tuple[int, int, str]]) -> set[tuple[int, int]]:
    positions = set()

    for r, c, _ in states:
        positions.add((r, c))

    return positions


GRID = [line.strip() for line in sys.stdin]
ROWS = len(GRID)
COLS = len(GRID[0])

SEEN_STATES = raycast()
unique_positions = getUniquePositions(SEEN_STATES)
print(len(unique_positions))
