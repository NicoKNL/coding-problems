from string import ascii_lowercase

class Solution:
    def secondHighest(self, s: str) -> int:
        digits = [int(x) for x in s if x not in ascii_lowercase]
        digits = list(set(digits))
        digits.sort()

        if len(digits) < 2:
            return -1
        else:
            return digits[-2]
