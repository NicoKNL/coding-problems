class Pokemon:
    def __init__(self, attack, defense, health):
        self.attack = attack
        self.defense = defense
        self.health = health
        self.is_picked = False


if __name__ == "__main__":
    n, k = map(int, input().split())

    pokemon = []
    for _ in range(n):
        A, D, H = map(int, input().split())
        pokemon.append(Pokemon(A, D, H))

    pokemon.sort(key=lambda p: p.attack, reverse=True)
    for i in range(k):
        pokemon[i].is_picked = True

    pokemon.sort(key=lambda p: p.defense, reverse=True)
    for i in range(k):
        pokemon[i].is_picked = True

    pokemon.sort(key=lambda p: p.health, reverse=True)
    for i in range(k):
        pokemon[i].is_picked = True

    count = 0
    for p in pokemon:
        if p.is_picked:
            count += 1

    print(count)
