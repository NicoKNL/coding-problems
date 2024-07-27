def countOnes(n: int) -> int:
    count = 0

    while n:
        if n & 1:
            count += 1
        n = n >> 1

    return count


class Solution:
    def sortByBits(self, arr: list[int]) -> list[int]:
        arr.sort()
        arr.sort(key=countOnes)
        return arr
