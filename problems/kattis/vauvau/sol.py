def determine_attacks(attack_days, rest_days, dog_attacks):
    attacks = 0
    rests = 0
    is_attacking = True
    for i in range(MAX):
        if is_attacking:
            if attacks == attack_days:
                is_attacking = False
                rests = 1
            else:
                dog_attacks[i] += 1
                attacks += 1
        else:
            if rests == rest_days:
                is_attacking = True
                dog_attacks[i] += 1
                attacks = 1
            else:
                rests += 1


if __name__ == "__main__":
    A, B, C, D = map(int, input().split())
    MAX = int(1e5)

    dog_attacks = [0 for _ in range(MAX)]
    determine_attacks(A, B, dog_attacks)
    determine_attacks(C, D, dog_attacks)

    men = list(map(int, input().split()))
    for man in men:
        if dog_attacks[man - 1] == 2:
            print("both")
        elif dog_attacks[man - 1] == 1:
            print("one")
        else:
            print("none")
