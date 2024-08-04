class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for c in s:
            t = t.replace(c, "", 1)
        
        return t
