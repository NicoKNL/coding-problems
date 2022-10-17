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


if __name__ == "__main__":
    p = int(input())

    for _ in range(p):
        k, n = map(int, input().split())
        print(k, solve(n))
