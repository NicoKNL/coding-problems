def digitSum(n: int) -> int:
    result = 0
    while n:
        result += n % 10
        n //= 10
    return result

class Solution:
    def countEven(self, num: int) -> int:
        return sum(digitSum(n) % 2 == 0 for n in range(2, num + 1))
