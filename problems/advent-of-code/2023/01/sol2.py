from string import ascii_lowercase
import sys

NUMBERS = [
    ".",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
]


def getLeftMostNumber(s: str) -> int:
    for i, c in enumerate(s):
        if c not in ascii_lowercase:
            return int(c)
        else:
            for num in NUMBERS:
                if s[i:].startswith(num):
                    return NUMBERS.index(num)


def getRightMostNumber(s: str) -> int:
    for i, c in enumerate(reversed(s)):
        if c not in ascii_lowercase:
            return int(c)
        else:
            for num in NUMBERS:
                if s[-(i + 1) :].startswith(num):
                    return NUMBERS.index(num)


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    total += 10 * getLeftMostNumber(line)
    total += getRightMostNumber(line)

print(total)
