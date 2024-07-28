class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        for i in range(x + 1):
            if i * i > x:
                return i - 1
