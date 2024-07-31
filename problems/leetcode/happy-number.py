def convert(n: int) -> int:
    n = sum(x * x for x in map(int, list(str(n))))
    return n

class Solution:
    def isHappy(self, n: int) -> bool:
        SEEN = set()
        SEEN.add(n)

        while True:
            n = convert(n)
            if n == 1:
                return True

            if n in SEEN:
                return False
            
            SEEN.add(n)
