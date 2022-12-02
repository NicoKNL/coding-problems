if __name__ == "__main__":
    n = int(input())
    kids = list(map(int, input().split()))

    bob = -1
    for i, kid in enumerate(kids):
        if kid == 0:
            bob = i

    score = 0
    for i, kid in enumerate(kids):
        score += (i + 1) * kid

    opt_score = score
    score1 = score

    i = bob - 1
    while i >= 0:
        score1 += kids[i]
        opt_score = max(score1, opt_score)
        i -= 1

    score2 = score
    i = bob + 1
    while i < n:
        score2 -= kids[i]
        opt_score = max(score2, opt_score)
        i += 1

    print(opt_score)
