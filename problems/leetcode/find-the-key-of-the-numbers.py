def f(nums: List[int], position: int) -> int:
    result = 9
    for num in nums:
        num //= position
        result = min(result, num % 10)
    return result

class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        nums = [num1, num2, num3]
        return 1000 * f(nums, 1000) + 100 * f(nums, 100) + 10 * f(nums, 10) + f(nums, 1)
