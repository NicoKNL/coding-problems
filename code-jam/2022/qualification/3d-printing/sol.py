TARGET = 1000000


class Printer:
    def __init__(self):
        self.C, self.M, self.Y, self.B = map(int, input().split())


def solve():
    printers = [Printer(), Printer(), Printer()]

    minimum_ink = [
        min([p.C for p in printers]),
        min([p.M for p in printers]),
        min([p.Y for p in printers]),
        min([p.B for p in printers]),
    ]

    if sum(minimum_ink) < TARGET:
        return "IMPOSSIBLE"

    ink = [0, 0, 0, 0]

    while sum(ink) < TARGET:
        needed = TARGET - sum(ink)

        for i in range(4):
            available = minimum_ink[i]

            if available:
                if needed <= available:
                    ink[i] += needed
                    minimum_ink[i] -= needed
                else:
                    ink[i] += available
                    minimum_ink[i] = 0

                break

    return " ".join([str(each) for each in ink])


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
