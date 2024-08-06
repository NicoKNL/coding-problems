class Solution:
    def reverse(self, x: int) -> int:
        negative = x < 0
        x = abs(x)
        result = 0
        while x:
            result += (x % 10)
            x //= 10
            
            if x:
                result *= 10

        if negative:
            result *= -1
        
        if result < -2**31 or result > 2**31 - 1:
            return 0

        return result
