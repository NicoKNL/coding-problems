class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        best = 0
        SEEN = dict()

        current = 0
        reset = 0
        for i, c in enumerate(s):
            if c not in SEEN:
                SEEN[c] = i
                current += 1
            else:
                reset = max(SEEN[c], reset)
                current = i - reset
                SEEN[c] = i

            best = max(best, current)
        
        return best
