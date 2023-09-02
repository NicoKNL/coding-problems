if __name__ == "__main__":
    n = int(input())

    signal = list(map(int, input().split()))

    problems = ["?" for _ in range(20)]

    for i in range(20):
        # print(signal)
        n = 2 ** (i + 1)
        idx = n // 2 - 1

        possible = True
        A_possible = True
        B_possible = True
        while possible and idx < len(signal) - 1:
            if A_possible:
                if signal[idx] - signal[idx + 1] != 1:
                    A_possible = False

            if B_possible:
                if signal[idx + 1] - signal[idx] != 1:
                    B_possible = False

            if not A_possible and not B_possible:
                possible = False

            idx += n

        if A_possible and B_possible:
            if signal[0]:
                problems[i] = "A"
                for idx in range(len(signal)):
                    signal[idx] -= 1
        elif A_possible:
            problems[i] = "A"
            for idx in range(len(signal)):
                if idx % n < n // 2:
                    signal[idx] -= 1

        elif B_possible:
            problems[i] = "B"
            for idx in range(len(signal)):
                if idx % n >= n // 2:
                    signal[idx] -= 1
        else:
            problems[i] = "x"

        # print(A_possible, B_possible)

    print(" ".join(problems))
