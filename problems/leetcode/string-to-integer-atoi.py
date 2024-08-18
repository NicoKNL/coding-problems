class Solution:
    def myAtoi(self, s: str) -> int:
        NUM = "0123456789"
        
        result = 0
        negative = False
        numstart = False
        for c in s:
            if numstart:
                if c in NUM:
                    result *= 10
                    result += NUM.index(c)
                else:
                    break
            else:
                if c in NUM:
                    numstart = True
                    result += NUM.index(c)
                elif c == " ":
                    continue
                elif c == "-":
                    negative = True
                    numstart = True
                elif c == "+":
                    numstart = True
                else:
                    break
        
        if negative:
            result *= -1

        result = min(result, 2 ** 31 - 1)
        result = max(result, -2 ** 31)

        return result
