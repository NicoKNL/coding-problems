class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        result = [1]

        for i in range(rowIndex):
            next_result = [1]
            for ii in range(1, len(result)):
                next_result.append(result[ii - 1] + result[ii])
            next_result.append(1)

            result = next_result

        return result
