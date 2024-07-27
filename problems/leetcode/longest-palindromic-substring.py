class Solution:
    def longestPalindrome(self, s: str) -> str:
        s = "|" + "|".join(s) + "|"
        palindrome = ""

        center = 0
        while center < len(s):
            L = center
            R = center
            radius = 0

            while L >= 0 and R < len(s) and s[L] == s[R]:
                L = center - (radius + 1)
                R = center + (radius + 1)
                radius += 1

            if 2 * radius + 1 > len(palindrome):
                palindrome = s[L + 1 : R]
            center += 1

        palindrome = palindrome.replace("|", "")
        return palindrome
