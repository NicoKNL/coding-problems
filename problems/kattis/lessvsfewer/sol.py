COUNT = ["number", "most", "fewest", "more", "fewer", "many", "few"]
MASS = ["amount", "most", "least", "more", "less", "much", "little"]

if __name__ == "__main__":
    M = {}

    n, q = map(int, input().split())

    for _ in range(n):
        noun, noun_type = input().split()
        M[noun] = noun_type

    for _ in range(q):
        words = input().split()
        used = words[0]
        noun = words[-1]

        correct = True
        if M[noun] == "c":
            if used not in COUNT:
                correct = False
        else:
            if used not in MASS:
                correct = False

        if correct:
            print("Correct!")
        else:
            print("Not on my watch!")
