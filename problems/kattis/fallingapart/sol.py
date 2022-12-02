if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort(reverse=True)

    alice = 0
    bob = 0
    for i, each in enumerate(nums):
        if i % 2 == 0:
            alice += each
        else:
            bob += each

    print(alice, bob)
