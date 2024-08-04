class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)

        gi = 0
        si = 0

        count = 0

        while si < len(s) and gi < len(g):
            if s[si] >= g[gi]:
                count += 1
                si += 1
                gi += 1
            else:
                si += 1
        
        return count
