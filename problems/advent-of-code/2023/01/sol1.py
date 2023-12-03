from string import ascii_lowercase
import sys

def getLeftMostNumber(s: str) -> int:
    for c in s:
        if c not in ascii_lowercase:
            return int(c)

def getRightMostNumber(s: str) -> int:
    for c in reversed(s):
        if c not in ascii_lowercase:
            return int(c)


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    total += 10 * getLeftMostNumber(line)
    total += getRightMostNumber(line)

print(total)