class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        M = dict()
        SEEN = set()

        s = s.split(" ")
        if len(pattern) != len(s):
            return False

        for a, b in zip(pattern, s):
            if a not in M:
                if b not in SEEN:
                    M[a] = b
                    SEEN.add(b)
                else:
                    return False
            
            else:
                if M[a] != b:
                    return False
        
        return True
