abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
    
def isValid(s):
    S = set()

    current = "."
    for c in s:
        if c == current:
            continue
        
        if c in S:
            return False
        
        S.add(c)
        current = c

    return True

def merge_trivial(towers):
    result = []
    reduced = False
    reduced_at = -1

    for i in range(len(towers) - 1):
        if reduced and reduced_at == i - 1:
            continue

        lhs = set(towers[i])
        rhs = set(towers[i + 1])
        if len(lhs) == 1 and len(rhs) == 1 and lhs == rhs:
            result.append(towers[i] + towers[i + 1])
            reduced = True
            reduced_at = i
        else:
            result.append(towers[i])
    
    if reduced and reduced_at != len(towers) - 2:
        result.append(towers[-1])
    elif not reduced:
        result.append(towers[-1])

    return reduced, sorted(result)

def merge_forced(towers, i):
    STARTSWITH, ENDSWITH = startsAndEnds(towers)

    result = towers[i]
    del towers[i]
    while len(towers):
        if (ENDSWITH[result[0]] > 1 or STARTSWITH[result[-1]] > 1) and not len(set(result)) == 1:
            break

        reduced = False
        for i in range(len(towers)):
            t = towers[i]
            if t[0] == result[-1]:
                result = result + t
                del towers[i]
                reduced = True
                break
            if t[-1] == result[0]:
                result = t + result
                del towers[i]
                reduced = True
                break
        if not reduced:
            break
    towers.append(result)
    return sorted(towers)

def startsAndEnds(towers):
    STARTSWITH = dict()
    ENDSWITH = dict()

    for c in abc:
        STARTSWITH[c] = 0
        ENDSWITH[c] = 0

    for t in towers:
        STARTSWITH[t[0]] += 1
        ENDSWITH[t[-1]] += 1
    
    return STARTSWITH, ENDSWITH


def solve():
    n = input()
    towers = list(sorted(input().split()))

    for t in towers:
        if not isValid(t):
            return "IMPOSSIBLE"

    while True:
        reduced, towers = merge_trivial(towers)
        if not reduced:
            break
    
    STARTSWITH, ENDSWITH = startsAndEnds(towers)

    for c in abc:
        if STARTSWITH[c] > 2:
            return "IMPOSSIBLE"

        if ENDSWITH[c] > 2:
            return "IMPOSSIBLE"
    
        # print(towers)
    i = 0
    while True:
        orig = len(towers)
        towers = merge_forced(towers, i)
        if len(towers) == orig:
            if i < len(towers) - 1:
                i += 1
            else:
                break
        else:
            i = 0

    result = "".join(towers)

    if isValid(result):
        return result
    return "IMPOSSIBLE"


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
