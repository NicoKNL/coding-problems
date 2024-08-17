def convertToBaseString(n: int, base: int) -> str:
    result = ""
    while n:
        result += str(n % base)
        n //= base
    return result

def isPalindrome(s: str) -> bool:
    return s == s[::-1]

class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        for base in range(2, n - 1):
            if not isPalindrome(convertToBaseString(n, base)):
                return False
        return True
