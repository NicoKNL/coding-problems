import sys


if __name__ == "__main__":
    OPPONENT = "ABC"
    ME = "XYZ"
    score = 0

    for line in sys.stdin:
        u, v = line.split()
        opp = OPPONENT.index(u)

        me = 0
        if v == "X":
            me = (opp - 1 + 3) % 3
        elif v == "Y":
            me = opp
        else:  # v == "Z":
            me = (opp + 1) % 3

        delta = (me - opp + 3) % 3

        if delta == 1:
            score += 6
        elif delta == 0:
            score += 3

        score += me + 1

    print(score)
