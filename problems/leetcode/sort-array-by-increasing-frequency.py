class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counted = [(num, nums.count(num)) for num in nums]
        counted.sort(key=lambda a: a[0], reverse=True)
        counted.sort(key=lambda b: b[1])
        return [x[0] for x in counted]
