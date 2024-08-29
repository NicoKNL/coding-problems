class UnionFind: 
    def __init__(self, n): 
        self.rank = [1] * n 
        self.parent = [i for i in range(n)]
        self.size = [1] * n

    def find(self, x): 
        if self.parent[x] != x: 
            self.parent[x] = self.find(self.parent[x]) 
        return self.parent[x] 

    def union(self, x, y): 
        a = self.find(x) 
        b = self.find(y) 

        if a == b: 
            return

        if self.rank[a] < self.rank[b]: 
            self.parent[a] = b

        elif self.rank[a] > self.rank[b]: 
            self.parent[b] = a 

        else: 
            self.parent[b] = a 
            self.rank[a] = self.rank[a] + 1
        
        self.size[a], self.size[b] = self.size[a] + self.size[b], self.size[a] + self.size[b]

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        UF = UnionFind(len(stones))
        for i in range(len(stones)):
            s1 = stones[i]
            for ii in range(i + 1, len(stones)):
                s2 = stones[ii]

                if s1[0] == s2[0] or s1[1] == s2[1]:
                    UF.union(i, ii)
        
        sets = dict()
        for i in range(len(stones)):
            idx = UF.find(i)
            sets[idx] = UF.size[idx]

        return sum(v - 1 for v in sets.values())
