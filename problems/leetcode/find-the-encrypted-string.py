class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        start = k % len(s)
        return s[start:] + s[:start]
