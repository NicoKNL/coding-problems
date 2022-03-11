if __name__ == "__main__":
    s = input()
    s = s.replace("-", "")
    nums = list(map(int, list(s)))

    base_list = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]

    result = [x * y for x, y in zip(nums, base_list)]
    total = sum(result)

    if total % 11 == 0:
        print(1)
    else:
        print(0)
