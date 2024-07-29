def stringAsInt(n: str) -> int:
    result = 0
    for i, c in enumerate(n[::-1]):
        result += int(c) * 10 ** i
    return result

def intAsString(n: int) -> str:
    if n == 0:
        return "0"
        
    result = ""
    while n > 0:
        result += str(n % 10)
        n //= 10
    return result[::-1]

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        a = stringAsInt(num1)
        b = stringAsInt(num2)
        return intAsString(a + b)
