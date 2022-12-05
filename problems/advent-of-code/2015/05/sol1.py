import sys

VOWELS = "aeiou"
FORBIDDEN = ["ab", "cd", "pq", "xy"]


def threeOrMoreVowels(s):
    count = 0
    for c in s:
        if c in VOWELS:
            count += 1
            if count >= 3:
                return True
    return False


def atLeastOneDuplicate(s):
    for i in range(len(s) - 1):
        a = s[i]
        b = s[i + 1]
        if a == b:
            return True
    return False


def noForbidden(s):
    for each in FORBIDDEN:
        if each in s:
            return False
    return True


def isNice(s):
    return threeOrMoreVowels(s) and atLeastOneDuplicate(s) and noForbidden(s)


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    nice = 0

    for s in lines:
        if isNice(s):
            nice += 1

    print(nice)
