if __name__ == "__main__":
    words = input().split()
    N = len(words)

    n = int(input())

    names = []
    for _ in range(n):
        names.append(input())

    start = 0
    team_a = []
    team_b = []
    pick_a = True
    while names:
        kid = (start + N - 1) % len(names)

        if pick_a:
            team_a.append(names[kid])
        else:
            team_b.append(names[kid])

        del names[kid]
        start = kid

        pick_a = not pick_a

    print(len(team_a))
    for kid in team_a:
        print(kid)
    print(len(team_b))
    for kid in team_b:
        print(kid)
