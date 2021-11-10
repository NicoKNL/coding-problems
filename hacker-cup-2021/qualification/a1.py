def isVowel(c):
    return c in "AEIOU"


def costToEdit(c1, c2):
    if c1 == c2:
        return 0
    elif isVowel(c1) == isVowel(c2):
        return 2
    else:
        return 1


def calculateEditDistance(s1, s2):
    cost = 0
    for i in range(len(s1)):
        cost += costToEdit(s1[i], s2[i])

    # print(s1, " --> ", s2, " = ", cost)
    return cost


def solve():
    s = str(input())

    unique_chars = set(s)
    unique_chars.add("A")
    unique_chars.add("Z")

    cost = 999999
    for c in unique_chars:
        cost = min(cost, calculateEditDistance(s, c * len(s)))

    return cost


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
