def trim(n: int, bits: int) -> int:
    return n & ((2 ** bits) - 1)


class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bits = len(bin(n)) - 2  # subtract "0b"

        A = int("10101010101010101010101010101010", 2)
        B = int("01010101010101010101010101010101", 2)

        A = trim(A, bits)
        B = trim(B, bits)

        A = A ^ n
        B = B ^ n

        return A == 0 or B == 0
