from math import sqrt
from collections import defaultdict

def primeFactorCount(n: int) -> Dict[int, int]:
    COUNT = defaultdict(int)

    while n % 2 == 0:
        COUNT[2] += 1
        n = n // 2
         
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            COUNT[i] += 1
            n = n // i
             
    if n > 2:
        COUNT[n] += 1
    
    return COUNT
         

class Solution:
    def trailingZeroes(self, n: int) -> int:
        TOTAL = defaultdict(int)

        for i in range(1, n + 1):
            COUNT = primeFactorCount(i)
            for k, v in COUNT.items():
                TOTAL[k] += v

        return min(TOTAL[2], TOTAL[5])
