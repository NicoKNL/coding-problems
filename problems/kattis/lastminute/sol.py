if __name__ == "__main__":
    a_uniq, b_uniq, a_reuse, b_reuse = map(int, input().split())

    total = 0

    if a_reuse:
        total += b_uniq
        b_uniq = 0

    if b_reuse:
        total += a_uniq
        a_uniq = 0

    if a_reuse and b_reuse:
        total += a_reuse * b_reuse

    if a_uniq and b_uniq:
        total += min(a_uniq, b_uniq)

    print(total)
