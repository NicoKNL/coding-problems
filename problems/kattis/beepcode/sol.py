if __name__ == "__main__":
    n = int(input())

    signal = list(map(int, input().split()))
    problems = ["?" for _ in range(20)]

    certainty = 20 in signal

    for i in range(20):
        n = 2 ** (i + 1)
        idx = n // 2 - 1

        if idx + 1 >= len(signal):
            if certainty and signal[0] > 0:
                problems[i] = "A"
                for idx in range(len(signal)):
                    signal[idx] = signal[idx] - 1

        elif signal[idx] - signal[idx + 1] == 1:
            problems[i] = "A"
            for idx in range(len(signal)):
                if idx % n < n // 2:
                    signal[idx] -= 1

        elif signal[idx + 1] - signal[idx] == 1:
            problems[i] = "B"
            for idx in range(len(signal)):
                if idx % n >= n // 2:
                    signal[idx] -= 1

        else:
            problems[i] = "x"

    print(" ".join(problems))
