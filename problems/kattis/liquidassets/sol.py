import re


def process(word):
    repeats = r"(.)\1+"
    once = r"\1"
    word = re.sub(repeats, once, word)

    final_word = ""
    for i, letter in enumerate(word):
        if i == 0 or i == len(word) - 1:
            final_word += letter
        elif letter not in "aeoiu":
            final_word += letter
    return final_word


N = int(input())

words = input().split()
for i in range(len(words)):
    words[i] = process(words[i])
print(" ".join(words))
