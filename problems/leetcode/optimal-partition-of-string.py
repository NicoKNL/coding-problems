from collections import defaultdict

def extractUniquePrefix(s: str) -> Tuple[str, str]:
    COUNTER = defaultdict(int)

    for i, c in enumerate(s):
        COUNTER[c] += 1
        if COUNTER[c] == 2:
            return s[:i], s[i:]
    
    return s, ""

class Solution:
    def partitionString(self, s: str) -> int:
        result = []

        while s:
            prefix, s = extractUniquePrefix(s)
            result.append(prefix)
        
        return len(result)
