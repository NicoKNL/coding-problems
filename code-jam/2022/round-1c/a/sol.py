from itertools import permutations

def simplify(s):
    result = ""

    for c in s:
        if not result.endswith(c):
            result += c
    
    return result

def isValid(s):
    M = set()

    current = "-1"
    for c in s:
        if c == current:
            continue
        
        if c in M:
            return False
        
        M.add(c)
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
    result = towers[i]
    del towers[i]

    while len(towers):
        # print(towers)
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

def isImpossible(s):
    M = set()
    prev = ""

    for c in s:
        if c == prev:
            continue
        
        if c in M:
            return True

        M.add(c)
        prev = c

    return False

def multipleStartWithSame(towers):
    starts = dict()

    for t in towers:
        if not t[0] in starts:
            starts[t[0]] = 1
        else:
            starts[t[0]] += 1
        
        if starts[t[0]] > 2:
            return True
    
    return False

def multipleEndWithSame(towers):
    starts = dict()

    for t in towers:
        if not t[-1] in starts:
            starts[t[-1]] = 1
        else:
            starts[t[-1]] += 1
        
        if starts[t[-1]] > 2:
            return True
    
    return False

def multiCenter(towers):
    M = dict()

    for i, t in enumerate(towers):
        for c in t[1:-2]:
            if c not in M:
                M[c] = i
            elif M[c] != i:
                return True

    return False


def solve():
    n = input()
    towers = list(sorted(input().split()))

    for t in towers:
        if isImpossible(t):
            return "IMPOSSIBLE"

    while True:
        reduced, towers = merge_trivial(towers)
        if not reduced:
            break
    
    if multipleStartWithSame(towers) or multipleEndWithSame(towers):
        return "IMPOSSIBLE"
    
    if multiCenter(towers):
        return "IMPOSSIBLE"

    # while True:
    #     reduced, towers = merge_forced(towers)
    #     if not reduced:
    #         break
    
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
    # print(towers) 
    for each in permutations(towers):
        joined = "".join(each)
        if isValid(joined):
            return joined

    return "IMPOSSIBLE"


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
