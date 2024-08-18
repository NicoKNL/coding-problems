COLUMNS = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ"
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        title = []
        while columnNumber > 0:
            title.append(columnNumber % 26)
                
            columnNumber = columnNumber // 26
            if title[-1] == 0:
                columnNumber -= 1

        return "".join(COLUMNS[i] for i in title[::-1])
