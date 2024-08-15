from collections import defaultdict


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        MONEY = defaultdict(int)

        for bill in bills:
            if bill == 5:
                MONEY[5] += 1
            elif bill == 10:
                MONEY[10] += 1
                if not MONEY[5]:
                    return False
                MONEY[5] -= 1
            else: # 20
                MONEY[20] += 1
                need = 15
                if MONEY[10]:
                    MONEY[10] -= 1
                    need -= 10
                
                need //= 5
                if MONEY[5] < need:
                    return False
                
                MONEY[5] -= need
        
        return True
                
