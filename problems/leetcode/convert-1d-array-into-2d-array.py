# from itertools import batched  # Not yet supported

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        # return list(batched(original, n))
        result = []

        i = 0
        row = []
        while i < len(original):
            row.append(original[i])
            i += 1
            if len(row) == n:
                result.append(row)
                row = []
        
        return result
