class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        result = list(s)

        for c, idx in zip(list(s), indices):
            result[idx] = c
        
        return "".join(result)
