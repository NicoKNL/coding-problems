class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n < 1:
            return False

        while n:
            if n == 1:
                return True

            if n % 4:
                return False

            n //= 4
