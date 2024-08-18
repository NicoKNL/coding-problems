from math import gcd


class Sequence:
    def __init__(self, length, gcd):
        self.length = length
        self.gcd = gcd


def solve(n):
    nums = list(map(int, input().split()))
    answer = [Sequence(0, 0)] * n
    answer[0] = Sequence(1, nums[0])

    for i in range(1, len(nums)):
        take = answer[-1].length * gcd(answer[-1].gcd, nums[i])
        start = nums[i]
        if take > start:
            answer[i] = Sequence(answer[i - 1].length, gcd(answer[i - 1], nums[i]))
        else:
            answer[i] = Sequence(1, nums[i])

    best = -1
    for each in answer:
        best = max(best, each.length * each.gcd)

    print(best)


T = int(input())

while T > 0:
    n = int(input())
    solve(n)
    T -= 1
