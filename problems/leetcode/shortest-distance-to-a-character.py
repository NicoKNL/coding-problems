INF = 999999999
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        Q = []
        result = [INF for _ in range(len(s))]
        for i, char in enumerate(s):
            if char == c:
                Q.append(i)
                result[i] = 0
        
        i = 0
        while i < len(Q):
            u = Q[i]
            val = result[u]
            i += 1

            if u > 0:
                if result[u - 1] == INF:
                    Q.append(u - 1)
                result[u - 1] = min(result[u - 1], val + 1)
            
            if u < len(s) - 1:
                if result[u + 1] == INF:
                    Q.append(u + 1)
                result[u + 1] = min(result[u + 1], val + 1)
            
        return result
