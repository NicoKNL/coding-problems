if __name__ == "__main__":
    seats, _ = map(int, input().split())
    people = list(map(int, input().split()))

    table = [0 for _ in range(seats)]

    for p in people:
        table[p - 1] = -1

    if table[0] != -1:
        anchor = people[0]
        table = table[anchor - 1 :] + table[: anchor - 1]

    for i in range(len(table)):
        if table[i] == -1:
            continue
        left = ((i - 1) + len(table)) % len(table)
        if table[left] == -1:
            table[i] = 1
        else:
            table[i] = table[left] + 1

    answer = 0

    for i, v in enumerate(table):
        if v == -1:
            left = ((i - 1) + len(table)) % len(table)
            empty_spaces = table[left]

            if empty_spaces > 2:
                answer += (empty_spaces - 2 + 1) // 2

    print(answer)
