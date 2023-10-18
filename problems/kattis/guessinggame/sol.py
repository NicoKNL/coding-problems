nums = [True for _ in range(11)]
nums[0] = False  # Flag 0 as impossible

while True:
    n = int(input())
    if n == 0:
        break

    ans = input()
    if ans == "too high":
        for i in range(n, 11):
            nums[i] = False

    elif ans == "too low":
        for i in range(0, n + 1):
            nums[i] = False

    else:  # right on
        if nums[n]:
            print("Stan may be honest")
        else:
            print("Stan is dishonest")

        nums = [True for _ in range(11)]
        nums[0] = False  # Flag 0 as impossible
