n = int(input())
nums = []
for _ in range(n):
    nums.append(int(input()))
nums = sorted(nums)

total = 0
for i, a in enumerate(nums):
    for ii, c in enumerate(nums):
        if ii - i <= 1:
            continue

        size = 0
        for iii in range(i + 1, ii):
            b = nums[iii]
            if a + b > c:
                size += 1

        if size > 0:
            total += 2**size - 1

print(total)
