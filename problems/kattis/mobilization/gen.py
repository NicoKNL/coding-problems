from random import random, randint

lines = ["30000 100000"]


for i in range(30000):
    cost = randint(1, 100000)
    health = random()
    potency = random()
    lines.append(f"{cost} {health} {potency}")

with open("large.in", "w") as f:
    f.writelines("\n".join(lines))
