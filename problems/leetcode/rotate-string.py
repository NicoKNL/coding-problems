def rotateString(s: str) -> str:
    return s[1:] + s[0]

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if s == goal:
            return True

        if sorted(s) != sorted(goal):
            return False
        
        for i in range(len(s)):
            s = rotateString(s)
            if s == goal:
                return True

        return False
