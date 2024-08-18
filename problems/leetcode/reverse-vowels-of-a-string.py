VOWELS = "aeiouAEIOU"

class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        L = 0
        R = len(s) - 1

        while L < R:
            if s[L] in VOWELS and s[R] in VOWELS:
                s[L], s[R] = s[R], s[L]
                L += 1
                R -= 1
                continue
            
            if s[L] not in VOWELS:
                L += 1

            if s[R] not in VOWELS:
                R -= 1
        
        return "".join(s)
