def narcissistic(value):
    digits = len(str(value))

    a = value
    b = 0

    while value:
        d = value % 10
        b += d**digits
        value //= 10

    return a == b
