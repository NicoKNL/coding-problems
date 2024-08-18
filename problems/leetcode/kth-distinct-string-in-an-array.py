from collections import defaultdict

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        M = defaultdict(int)

        for each in arr:
            M[each] += 1
        
        counter = 0
        for s, count in M.items():
            if count == 1:
                counter += 1
                if counter == k:
                    return s

        return ""
