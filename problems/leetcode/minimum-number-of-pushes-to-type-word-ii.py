from collections import defaultdict

class Solution:
    def minimumPushes(self, word: str) -> int:
        M = defaultdict(int)

        for c in word:
            M[c] += 1
        
        count = 0
        presses = 1
        buttons = 8

        for v in sorted(M.values(), reverse=True):
            count += presses * v
            buttons -= 1

            if buttons == 0:
                presses += 1
                buttons = 8
        
        return count
