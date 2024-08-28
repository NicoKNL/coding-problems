class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        sequences = "".join(map(str, [0] + flowerbed + [0]))
        space = [(len(seq) - 1) // 2 for seq in sequences.split("1") if seq]
        return sum(space) >= n
