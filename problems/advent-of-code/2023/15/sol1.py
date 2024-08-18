import sys


def hash(s: str) -> str:
    value = 0
    for c in s:
        value += ord(c)
        value *= 17
        value %= 256
    return value


steps = next(sys.stdin).strip().split(",")

total = 0
for step in steps:
    total += hash(step)

print(total)
