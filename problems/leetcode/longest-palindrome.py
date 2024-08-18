from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> int:
        COUNT = defaultdict(int)
        for c in s:
            COUNT[c] += 1

        max_length = 0
        taken_odd = False
        for c, count in COUNT.items():
            max_length += (count // 2) * 2
            if not taken_odd and count % 2 == 1:
                max_length += 1
                taken_odd = True
        
        return max_length
