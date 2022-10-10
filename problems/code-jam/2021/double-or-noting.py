GLOBAL_MAX = 15

def shiftleft(binary_number):
    return f"{binary_number}0"


def invert(binary_number): 
    result = ""
    started = False

    for bit in binary_number:
        if bit == "0":
            result += "1"
            started = True
        elif bit == "1" and started:
            result += "0"

    return result


def recurse(s, e, current, best):
    if current >= best[0]:
        return 

    if s == e:
        best[0] = min(best[0], current)
        return

    recurse(shiftleft(s), e, current + 1, best)
    recurse(invert(s), e, current + 1, best)

def solve():
    S, E = str(input()).split(" ")

    best = [GLOBAL_MAX]
    recurse(S, E, 0, best)

    if best[0] == GLOBAL_MAX:
        return "IMPOSSIBLE"
    else:
        return best[0]


if __name__ == "__main__":
    T = int(input())
    c = 1

    while T:
        print(f"Case #{c}: {solve()}")
        c += 1
        T -= 1
