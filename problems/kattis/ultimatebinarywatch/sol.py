digits = []


def makeDigit(n):
    digit = "...."

    i = 0
    while n:
        if n % 2 == 1:
            digit = digit[:i] + "*" + digit[(i + 1) :]

        n = n // 2
        i += 1

    return digit


if __name__ == "__main__":
    for i in range(10):
        digits.append(makeDigit(i))

    time = input()

    d1 = digits[int(time[0])]
    d2 = digits[int(time[1])]
    d3 = digits[int(time[2])]
    d4 = digits[int(time[3])]

    print(f"{d1[3]} {d2[3]}   {d3[3]} {d4[3]}")
    print(f"{d1[2]} {d2[2]}   {d3[2]} {d4[2]}")
    print(f"{d1[1]} {d2[1]}   {d3[1]} {d4[1]}")
    print(f"{d1[0]} {d2[0]}   {d3[0]} {d4[0]}")
