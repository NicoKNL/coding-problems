from random import choice, randint

MAX_LENGTH = 200


def insertWord(s, word, i):
    return s[:i] + word + s[i:]


def expandStringToMaxLength(base, word, maxlen):
    if len(base) + len(word) > maxlen:
        return base

    insert_location = randint(0, len(base))

    return expandStringToMaxLength(
        insertWord(base, word, insert_location), word, maxlen
    )


def generate():
    with open("words.txt", "r") as f:
        words = f.readlines()

    words = [w.rstrip("\n") for w in words]
    word = choice(words)

    # return expandStringToMaxLength(word, word, 2 * len(word))
    # return expandStringToMaxLength(word, word, randint(2 * len(word), MAX_LENGTH))
    return expandStringToMaxLength(word, word, randint(150, MAX_LENGTH))


if __name__ == "__main__":
    for i in range(10):
        s = generate()
        with open(f"input-{i}.txt", "w+") as f:
            f.write(s)