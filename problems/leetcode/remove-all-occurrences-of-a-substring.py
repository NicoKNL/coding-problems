class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        replace = True
        while replace:
            replace = False
            for i in range(len(s) - len(part) + 1):
                if s[i:].startswith(part):
                    s = s[:i] + s[i + len(part):]
                    replace = True
                    break
        return s
