from itertools import permutations

class Solution:
    def minimumSum(self, num: int) -> int:
        nums = [","]

        while num:
            nums.append(str(num % 10))
            num //= 10

        best = 10e9    
        for each in permutations(nums):
            each = "".join(each)
            a, b = each.split(",")
            if not a:
                a = 0
            if not b:
                b = 0
            best = min(best, int(a) + int(b))
        
        return best
