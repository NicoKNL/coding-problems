import sys
from itertools import combinations

WEAPONS = [(8, 4, 0), (10, 5, 0), (25, 6, 0), (40, 7, 0), (74, 8, 0)]
ARMOR = [(0, 0, 0), (13, 0, 1), (31, 0, 2), (53, 0, 3), (75, 0, 4), (102, 0, 5)]
RINGS = [
    (0, 0, 0),
    (0, 0, 0),
    (25, 1, 0),
    (50, 2, 0),
    (100, 3, 0),
    (20, 0, 1),
    (40, 0, 2),
    (80, 0, 3),
]


class Char:
    def __init__(self, hp, damage, armor):
        self.hp = hp
        self.damage = damage
        self.armor = armor


def fight(ME, BOSS):
    my_turn = True
    while ME.hp > 0 and BOSS.hp > 0:
        if my_turn:
            damage = max(ME.damage - BOSS.armor, 1)
            BOSS.hp -= damage
        else:
            damage = max(BOSS.damage - ME.armor, 1)
            ME.hp -= damage

        my_turn = not my_turn


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    boss_data = [int(l.split(" ")[-1]) for l in lines]

    most_gold = 0

    for weapon in WEAPONS:
        for armor in ARMOR:
            for ring1, ring2 in combinations(RINGS, 2):
                cost = weapon[0] + armor[0] + ring1[0] + ring2[0]
                attack = weapon[1] + armor[1] + ring1[1] + ring2[1]
                defense = weapon[2] + armor[2] + ring1[2] + ring2[2]
                ME = Char(100, attack, defense)
                BOSS = Char(*boss_data)

                fight(ME, BOSS)
                if ME.hp <= 0:
                    most_gold = max(most_gold, cost)

    print(most_gold)
