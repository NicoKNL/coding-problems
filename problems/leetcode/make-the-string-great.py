def isGood(s: str):
    for i in range(len(s) - 1):
        if s[i] != s[i + 1]:
            if s[i] == s[i + 1].lower() or s[i] == s[i + 1].upper():
                return i
    return -1

class Solution:
    def makeGood(self, s: str) -> str:
        while True:
            index = isGood(s)
            if index == -1:
                return s
            else:
                s = s[:index] + s[index + 2:]
