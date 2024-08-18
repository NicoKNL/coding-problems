def ones(num: int) -> str:
    return ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"][num]

def tens(num: int) -> str:
    return ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"][num]

def hundreds(num: int) -> str:
    return f"{ones(num)} Hundred"

def parse(num: int, suffix: str) -> str:
    result = []

    if num >= 100:
        result.append(hundreds((num // 100) % 10))

    if num % 100 >= 20:
        result.append(tens((num // 10) % 10))
        if num % 10 != 0:
            result.append(ones(num % 10))
    elif num % 100 != 0:
        result.append(ones(num % 100))
    
    if suffix:
        result.append(suffix)

    return " ".join(result)

class Solution:
    def numberToWords(self, num: int) -> str:
        SUFFIXES = ["", "Thousand", "Million", "Billion"]
        result = []
        i = 0
        while num:
            if num % 1000 != 0:
                result.append(parse(num % 1000, SUFFIXES[i]))
            num //= 1000
            i += 1
        
        if not result:
            result = ["Zero"]
        return " ".join(result[::-1])
