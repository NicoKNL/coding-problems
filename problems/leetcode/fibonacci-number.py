class Solution:
    def fib(self, n: int) -> int:
        FIB = [0, 1]

        while len(FIB) <= n:
            FIB.append(FIB[-1] + FIB[-2])
            
        return FIB[n]
