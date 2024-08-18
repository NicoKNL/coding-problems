from math import lcm
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return lcm(n, 2)
