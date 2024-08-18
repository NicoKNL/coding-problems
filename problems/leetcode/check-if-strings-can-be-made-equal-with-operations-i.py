class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        a, b, c, d = list(s1)
        options = [a + b + c + d, c + b + a + d, a + d + c + b, c + d + a + b]
        return s2 in options
