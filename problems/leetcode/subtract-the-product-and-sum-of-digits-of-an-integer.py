def product(n: int) -> int:
    p = 1
    while n:
        p *= n % 10
        n //= 10
    return p

def sum(n: int) -> int:
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        return product(n) - sum(n)
