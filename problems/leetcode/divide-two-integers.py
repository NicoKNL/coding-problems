def compute(dividend: int, divisor: int) -> Tuple[int, int]:
    negative = False
    negative_dividend = False

    if dividend < 0:
        negative = True
        negative_dividend = True
    
    if divisor < 0:
        negative = not negative
    
    dividend = abs(dividend)
    divisor = abs(divisor)

    TABLE = [0, divisor]
    TIMES = [0, 1]
    while TABLE[-1] < dividend:
        TABLE.append(TABLE[-1] + TABLE[-2])
        TIMES.append(TIMES[-1] + TIMES[-2])

    count = 0
    if TABLE[-1] == dividend:
        count = TIMES[-1]
        dividend -= TABLE[-1]
    else:
        count = TIMES[-2]
        dividend -= TABLE[-2]
    
    if negative_dividend:
        dividend *= -1

    if negative:
        count *= -1

    return count, dividend
        

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        count = 0
        while abs(dividend) >= abs(divisor):
            tmp, dividend = compute(dividend, divisor)
            count += tmp

        count = min(count, 2 ** 31 - 1)
        count = max(count, -2 ** 31)

        return count
