class Solution:
    def reverseBits(self, n: int) -> int:
        s = bin(n)[2:].rjust(32, "0")[::-1]
        return int(s, 2)
