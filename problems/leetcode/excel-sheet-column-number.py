ABC = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        num = 0

        for i, char in enumerate(columnTitle[::-1]):
            num += (26 ** i) * ABC.index(char)

        return num
