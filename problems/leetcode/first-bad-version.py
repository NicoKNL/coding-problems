# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        LO = 1
        HI = n + 1

        bad = -1
        while LO <= HI:
            MID = (LO + HI) // 2
            
            if isBadVersion(MID):
                bad = MID
                HI = MID - 1
            else:
                LO = MID + 1
        
        return bad
