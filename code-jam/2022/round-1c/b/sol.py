def square_of_sum(nums):
    s = sum(nums)
    return s * s

def sum_of_squares(nums):
    return sum(x * x for x in nums)

def solve():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    SQUARE_OF_SUM = sum(nums) * sum(nums)
    SUM_OF_SQUARES = sum(x * x for x in nums)
    # print(SQUARE_OF_SUM, SUM_OF_SQUARES)

    if SQUARE_OF_SUM == SUM_OF_SQUARES:
        return " ".join(["0" for _ in range(k)])
    elif SQUARE_OF_SUM == 0:
        return "IMPOSSIBLE"
    elif SQUARE_OF_SUM < SUM_OF_SQUARES:
        for i in range(15000):
            new_nums = [x for x in nums]
            new_nums.append(i)

            sqos = square_of_sum(new_nums)
            sosq = sum_of_squares(new_nums)

            if sqos == sosq:
                answer = ["0" for _ in range(k - 1)]
                answer.append(str(i))
                return " ".join(answer)

    else: # SQUARE_OF_SUM > SUM_OF_SQUARES:
        for i in range(15000):
            i *= -1
            new_nums = [x for x in nums]
            new_nums.append(i)

            sqos = square_of_sum(new_nums)
            sosq = sum_of_squares(new_nums)

            if sqos == sosq:
                answer = ["0" for _ in range(k - 1)]
                answer.append(str(i))
                return " ".join(answer)
    
    return "IMPOSSIBLE"


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
