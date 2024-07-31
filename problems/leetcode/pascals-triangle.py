class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]
        for i in range(1, numRows):
            row = [1]
            for ii in range(len(triangle[-1])):
                if ii == len(triangle[-1]) - 1:
                    row.append(1)
                else:
                    row.append(triangle[-1][ii] + triangle[-1][ii + 1])
            triangle.append(row)

        return triangle
