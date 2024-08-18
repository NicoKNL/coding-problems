ROMAN = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "C": 100,
    "D": 500,
    "M": 1000,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        s = "".join(reversed(s))
        total = ROMAN[s[0]]
        for i in range(1, len(s)):
            pre = s[i - 1]
            cur = s[i]
            if ROMAN[pre] > ROMAN[cur]:
                total -= ROMAN[cur]
            else:
                total += ROMAN[cur]
        return total
