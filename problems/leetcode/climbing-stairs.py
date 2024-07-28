class Solution:
    def climbStairs(self, n: int) -> int:
        stairs = [0 for _ in range(n + 1)]
        stairs[0] = 1

        for i in range(1, n + 1):
            if i - 1 >= 0:
                stairs[i] += stairs[i - 1]
            if i - 2 >= 0:
                stairs[i] += stairs[i - 2]

        return stairs[-1]
