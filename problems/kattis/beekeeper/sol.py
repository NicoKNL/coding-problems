VOWELS = "aeiouy"


def count(word):
    count = 0
    for i in range(len(word) - 1):
        if word[i] == word[i + 1] and word[i] in VOWELS:
            count += 1
    return count


if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break

        best_count = -1
        best_word = ""
        for _ in range(n):
            word = input()
            c = count(word)

            if c > best_count:
                best_count = c
                best_word = word

        print(best_word)
