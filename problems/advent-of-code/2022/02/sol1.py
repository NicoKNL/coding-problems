import sys

OPPONENT = "ABC"
ME = "XYZ"
T = ["ROCK", "PAPER", "SCISSORS"]

if __name__ == "__main__":
    score = 0

    for line in sys.stdin:
        u, v = line.split()
        opp = OPPONENT.index(u)
        me = ME.index(v)

        delta = me - opp
        print(T[opp], T[me], delta)

        if delta == 1 or delta == -2:
            score += 6
        elif delta == 0:
            score += 3

        score += me + 1

    print(score)
