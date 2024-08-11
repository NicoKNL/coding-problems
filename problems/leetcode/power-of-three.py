class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n < 1:
            return False

        while n:
            if n == 1:
                return True
            
            if n % 3:
                return False

            n //= 3
