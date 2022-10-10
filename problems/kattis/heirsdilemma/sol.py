def noZeroes(n):
    s = str(n)

    for each in s:
        if each == "0":
            return False

    return True


def allDigitsUnique(n):
    s = str(n)

    return len(set(s)) == 6


def divisibleByAllDigits(n):
    s = str(n)

    for each in s:
        si = int(each)

        if n % si != 0:
            return False

    return True


if __name__ == "__main__":
    start, end = map(int, input().split())

    possibilities = 0

    for i in range(start, end + 1):
        if noZeroes(i):
            if allDigitsUnique(i):
                if divisibleByAllDigits(i):
                    possibilities += 1

    print(possibilities)
