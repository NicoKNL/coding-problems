from collections import defaultdict

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        counter = defaultdict(int)
        
        for u, v in edges:
            counter[u] += 1
            if counter[u] > 2:
                return u
            
            counter[v] += 1
            if counter[v] > 2:
                return v
        
        for k, v in counter.items():
            if v == 2:
                return k
