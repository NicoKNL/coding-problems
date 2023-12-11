import sys


def parseNumbers(line: str) -> list[int]:
    return list(map(int, line.split(" ")))


def getFinalDeltas(nums: list[int]) -> list[int]:
    deltas = []
    while any(nums):
        next_nums = []

        for i in range(len(nums) - 1):
            a = nums[i]
            b = nums[i + 1]
            next_nums.append(b - a)

        deltas.append(next_nums[-1])
        nums = next_nums

    return deltas


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    numbers = parseNumbers(line)
    deltas = getFinalDeltas(numbers)
    next_number = numbers[-1] + sum(deltas)
    total += next_number

print(total)
