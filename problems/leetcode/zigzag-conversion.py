class IndexBouncer:
    def __init__(self, n):
        self.i = 0
        self.indices = list(range(n))
        self.indices += self.indices[1:-1][::-1]

    def __iter__(self):
        return self

    def __next__(self) -> int:
        idx = self.indices[self.i]
        self.i = (self.i + 1) % len(self.indices)
        return idx

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        words = ["" for _ in range(numRows)]
        idx = IndexBouncer(numRows)
        for c in s:
            words[next(idx)] += c
            
        return "".join(words)
