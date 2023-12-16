import sys


def parseData(line: str) -> tuple[str, tuple[int]]:
    record, groups = line.split(" ")
    groups = tuple(map(int, groups.split(",")))
    return record, groups


def fits(s: str, start: int, end: int) -> bool:
    # Check for out of bounds
    if start - 1 < 0 or end + 1 >= len(s):
        return False

    # Check if segment can be surrounded by non-hash chars
    if s[start - 1] == "#" or s[end + 1] == "#":
        return False

    # Check if we're skipping any "#"
    if "#" in s[:start]:
        return False

    # Check if segment is possible
    for i in range(start, end + 1):
        if s[i] == ".":
            return False

    return True


def dfs(record: str, groups: tuple[int]) -> int:
    if not groups:
        return 0 if "#" in record else 1

    size = groups[0]
    groups = groups[1:]

    count = 0
    for end in range(len(record)):
        start = end - (size - 1)

        if fits(record, start, end):
            count += dfs(record[end + 1 :], groups)

    return count


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    record, groups = parseData(line)
    record = "." + record + "."
    total += dfs(record, groups)

print(total)
