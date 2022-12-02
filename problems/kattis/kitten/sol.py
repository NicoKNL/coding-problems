if __name__ == "__main__":
    K = int(input())

    tree = [-1 for _ in range(101)]

    while True:
        branch = list(map(int, input().split()))

        if branch[0] == -1:
            break

        parent = branch[0]
        for child in branch[1:]:
            tree[child] = parent

    path = [K]
    while True:
        parent = tree[path[-1]]

        if parent == -1:
            break

        path.append(parent)

    print(" ".join(map(str, path)))
