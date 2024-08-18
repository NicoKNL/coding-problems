def solve():
    _, w = map(int, input().split())
    words = []
    for _ in range(w):
        words.append(input())

    WORD = words[0]
    for w in words[1:]:
        for i in range(len(w), -1, -1):
            if WORD.endswith(w[0:i]):
                WORD += w[i:]
                break

    print(len(WORD))


n = int(input())

for _ in range(n):
    solve()
