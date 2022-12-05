import sys

VOWELS = "aeiou"
FORBIDDEN = ["ab", "cd", "pq", "xy"]


def twoPair(s):
    for i in range(2, len(s) - 1):
        a = s[i - 2 : i]
        b = s[i:]

        if a in b:
            return True
    return False


def atLeastOneDuplicate(s):
    for i in range(len(s) - 2):
        a = s[i]
        b = s[i + 2]
        if a == b:
            return True
    return False


def isNice(s):
    return twoPair(s) and atLeastOneDuplicate(s)


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    nice = 0

    for s in lines:
        if isNice(s):
            nice += 1

    print(nice)
