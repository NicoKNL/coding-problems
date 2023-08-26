import sys


class Ingredient:
    def __init__(self, s):
        s = s.replace(",", " ").replace(":", " ").split(" ")
        s = [s for s in s if s]
        self.name = s[0]
        self.capacity = int(s[2])
        self.durability = int(s[4])
        self.flavor = int(s[6])
        self.texture = int(s[8])
        self.calories = int(s[10])


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    ingredients = [Ingredient(s) for s in lines]

    best = 0
    for i in range(100):
        for ii in range(100 - i):
            for iii in range(100 - ii - i):
                iv = 100 - iii - ii - i

                capacity = (
                    i * ingredients[0].capacity
                    + ii * ingredients[1].capacity
                    + iii * ingredients[2].capacity
                    + iv * ingredients[3].capacity
                )
                capacity = max(capacity, 0)

                durability = (
                    i * ingredients[0].durability
                    + ii * ingredients[1].durability
                    + iii * ingredients[2].durability
                    + iv * ingredients[3].durability
                )
                durability = max(durability, 0)

                flavor = (
                    i * ingredients[0].flavor
                    + ii * ingredients[1].flavor
                    + iii * ingredients[2].flavor
                    + iv * ingredients[3].flavor
                )
                flavor = max(flavor, 0)

                texture = (
                    i * ingredients[0].texture
                    + ii * ingredients[1].texture
                    + iii * ingredients[2].texture
                    + iv * ingredients[3].texture
                )
                texture = max(texture, 0)

                total = capacity * durability * flavor * texture
                best = max(best, total)

    print(best)
