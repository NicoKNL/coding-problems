class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        single = True
        while i < len(bits):
            if bits[i] == 1:
                i += 2
                single = False
            else:
                i += 1
                single = True

        return single
