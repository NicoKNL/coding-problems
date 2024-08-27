L = 0
R = 1

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balance = [0, 0]
        count = 0

        for c in s:
            if c == "L":
                balance[L] += 1
            else:
                balance[R] += 1

            if balance[L] == balance[R]:
                count += 1
                balance = [0, 0]
        
        return count
