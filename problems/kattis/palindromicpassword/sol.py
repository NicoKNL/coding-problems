def split(n):
    digits = []
    for i in reversed(range(1, 7)):
        v = n % (10**i)
        v = v // (10 ** (i - 1))
        digits.append(v)
    return digits


def isPalindrome(n):
    digits = split(n)

    if digits[0] == digits[-1]:
        if digits[1] == digits[-2]:
            if digits[2] == digits[-3]:
                return True

    return False


def solve():
    v = int(input())

    sign = -1
    i = 1
    while True:
        if isPalindrome(v):
            print(v)
            break

        v += sign * i
        sign *= -1
        i += 1


if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        solve()
