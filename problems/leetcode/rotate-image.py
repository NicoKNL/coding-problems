class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rotated_matrix = [list(reversed(x)) for x in zip(*matrix)]
        for r in range(len(matrix)):
            matrix[r][:] = rotated_matrix[r]
