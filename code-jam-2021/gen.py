from random import randint

with open("tmp.txt", "w+") as f:
    T = randint(1, 100)
    f.write(f"{T}\n")

    for i in range(T):
        N = randint(1, 30)
        K = randint(1, 1000000000)
        f.write(f"{N} {K}\n")

        for ii in range(N):
            f.write(f"{randint(1, K)} ")

        f.write("\n")