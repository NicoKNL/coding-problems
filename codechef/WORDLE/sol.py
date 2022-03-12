if __name__ == "__main__":
    n = int(input())

    for i in range(n):
        word = list(input())
        guess = list(input())

        M = ["G" if w == b else "B" for w, b in zip(word, guess)]
        print("".join(M))
