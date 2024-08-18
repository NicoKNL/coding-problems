def sumDigits(num: int) -> int:
    n = 0
    while num:
        n += num % 10
        num //= 10
    
    return n

class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            num = sumDigits(num)
            
        return num
