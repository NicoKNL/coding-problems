# TODO: finish
def computeDepth(n):
    depth = 1
    nodes = 1

    while nodes < n:
        depth += 1
        nodes = treeSize(depth)

    return depth


def treeSize(n):
    return pow(2, n) - 1


def nodesAtDepth(n):
    return treeSize(n) - treeSize(n - 1)


def sequenceToRational(sequence):
    left = 1
    right = 1

    for char in sequence:
        if char == "L":
            right = left + right
        else:
            left = left + right

    return f"{left}/{right}"


def solve(n):
    depth = computeDepth(n)

    sequence = ""
    while depth > 1:
        index = n - treeSize(depth - 1) - 1
        if index < nodesAtDepth(depth) / 2:
            sequence += "L"
            n = n - nodesAtDepth(depth) // 2
        else:
            sequence += "R"
            n = n - nodesAtDepth(depth)

        depth -= 1

    return sequenceToRational(sequence)


def determineN(p, q):
    root = [1, 1]
    tmp = [p, q]

    sequence = []

    height = 0

    while tmp != root:
        # height += 1
        print(tmp)
        if tmp[0] > tmp[1]:
            div = tmp[0] // tmp[1]
            height += div
            tmp[0] -= div * tmp[1]
            sequence.append([div, "r"])
            # sequence += "r"

        else:
            div = tmp[1] // tmp[0]
            height += div
            tmp[1] -= div * tmp[0]
            sequence.append([div, "l"])
            # sequence += "l"

        if tmp[0] == 0:
            tmp[0] = 1

        if tmp[1] == 0:
            tmp[1] = 1

    sequence = sequence[::-1]

    # pos = 1
    # for count, c in sequence:
    # if c == "l":
    # pos = pow(2, count) * pos - 1
    # else:
    # pos = 2 * pow(pos, count)

    nodes_above_height = 0
    if height > 0:
        nodes_above_height = (2 << (height - 1)) - 1
    print("done")
    return nodes_above_height + pos


if __name__ == "__main__":
    p = int(input())

    for _ in range(p):
        k, n = input().split()
        k = int(k)
        n = str(n).split("/")
        p = int(n[0])
        q = int(n[1])

        n = determineN(p, q)
        print(k, solve(n + 1))
