marker = 1000000000


def solve():
    N, M = [int(x) for x in str(input()).split(" ")]
    A = [0]
    A.extend([int(x) for x in str(input()).split(" ")])
    B = [int(x) for x in str(input()).split(" ")]
    C = [marker] * (N + 1)

    # Dist from left
    has_train = False
    train_pos = -1
    for i in range(1, len(A)):
        if A[i] == 1:
            has_train = True
            train_pos = i
            C[i] = 0
        elif has_train:
            C[i] = i - train_pos
            i += 1

    # Dist from right
    has_train = False
    train_pos = -1
    for i in range(len(A) - 1, 0, -1):
        if A[i] == 2:
            has_train = True
            train_pos = i
            C[i] = 0
        elif has_train:
            C[i] = min(C[i], train_pos - i)
            i += 1

    # Set magic station
    C[1] = 0

    # Build result
    result = ""
    for i in range(len(B)):
        if i > 0:
            result += " "

        destination = B[i]
        if C[destination] == marker:
            result += "-1"
        else:
            result += str(C[destination])

    print(result)


if __name__ == "__main__":
    T = int(input())

    while T:
        solve()
        T -= 1