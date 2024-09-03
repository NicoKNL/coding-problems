from string import ascii_lowercase

def asNumber(c: str) -> int:
    return ascii_lowercase.index(c) + 1


def sumDigits(num: int) -> int:
    result = 0
    while num:
        result += num % 10
        num //= 10

    return result

class Solution:
    def getLucky(self, s: str, k: int) -> int:
        total = ""

        for c in s:
            total += str(asNumber(c))

        total = int(total)
        for _ in range(k):
            total = sumDigits(total)        

        return total
