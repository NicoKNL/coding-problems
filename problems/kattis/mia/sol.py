INF = 1e9

if __name__ == "__main__":
    while True:
        s0, s1, r0, r1 = map(int, input().split())

        if s0 == 0 and s1 == 0 and r0 == 0 and r1 == 0:
            break

        p1 = [s0, s1]
        p2 = [r0, r1]

        p1.sort(reverse=True)
        p2.sort(reverse=True)

        p1 = 10 * p1[0] + p1[1]
        p2 = 10 * p2[0] + p2[1]

        if p1 == 21:
            p1 = INF
        if p2 == 21:
            p2 = INF

        if s0 == s1:
            p1 *= 1000
        if r0 == r1:
            p2 *= 1000

        if p1 > p2:
            print("Player 1 wins.")
        elif p1 < p2:
            print("Player 2 wins.")
        else:
            print("Tie.")
