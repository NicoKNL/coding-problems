# TARGET_ROW = 2981
# TARGET_COL = 3075
TARGET_ROW = 2
TARGET_COL = 1
START_ROW = TARGET_ROW + TARGET_COL - 1
print("start_row: ", START_ROW)
JUMPS = START_ROW * (START_ROW + 1) // 2
print("jumps: ", JUMPS)


def mulmod(a: int, b: int, mod: int) -> int:
    b = b % mod
    x = 0
    y = a % mod

    while b:
        if b % 2 == 1:
            x = (x + y) % mod
        y = (2 * y) % mod
        b //= 2

    return x % mod


MUL = 252533
MOD = 33554393

row = START_ROW
col = 1
diagonal = 1

code = 20151125 * mulmod(MUL, JUMPS, MOD)
code %= MOD
print(code)

while row != TARGET_ROW and col != TARGET_COL:
    print(".")
    row -= 1
    col += 1
    code = (code * MUL) % MOD

    if row == TARGET_ROW and col == TARGET_COL:
        print(code)
        break
