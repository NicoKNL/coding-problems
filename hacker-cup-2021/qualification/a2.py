alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
swap_map = [[]]


def computeSwapMap():
    # reset
    global swap_map
    swap_map = [[999999] * 26 for i in range(26)]

    # edges
    n = int(input())
    for i in range(n):
        swap = str(input())
        a = ord(swap[0]) - 65
        b = ord(swap[1]) - 65

        swap_map[a][b] = 1

    # self swaps
    for c1 in range(len(alphabet)):
        swap_map[c1][c1] = 0

    # compute shortest paths
    for c3 in range(len(alphabet)):
        for c1 in range(len(alphabet)):
            for c2 in range(len(alphabet)):
                if swap_map[c1][c2] > swap_map[c1][c3] + swap_map[c3][c2]:
                    swap_map[c1][c2] = swap_map[c1][c3] + swap_map[c3][c2]


def calculateEditDistance(s1, s2):
    cost = 0
    for i in range(len(s1)):
        a = ord(s1[i]) - 65
        b = ord(s2[i]) - 65
        char_cost = swap_map[a][b]

        if char_cost == 999999:
            return 999999
        else:
            cost += char_cost

    # print(s1, " --> ", s2, " = ", cost)
    return cost


def solve():
    s = str(input())

    computeSwapMap()

    unique_chars = sorted(set("ABCDEFGHIJKLMNOPQRSTUVWXYZ"))

    cost = 999999
    for c in unique_chars:
        cost = min(cost, calculateEditDistance(s, c * len(s)))

    if cost == 999999:
        return -1
    else:
        return cost


if __name__ == "__main__":

    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
