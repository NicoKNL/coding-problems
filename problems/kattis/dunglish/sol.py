from collections import defaultdict
from functools import reduce
from operator import mul

OK = defaultdict(set)
NOK = defaultdict(set)

if __name__ == "__main__":
    n = int(input())
    sentence = input().split()

    m = int(input())
    for _ in range(m):
        a, b, state = input().split()
        if state == "correct":
            OK[a].add(b)
        else:
            NOK[a].add(b)

    ok_translations = []
    nok_translations = []

    for word in sentence:
        ok_translations.append(len(OK[word]))
        nok_translations.append(len(NOK[word]))

    total_ok = reduce(mul, ok_translations, 1)

    total_nok = 1
    for ok, nok in zip(ok_translations, nok_translations):
        total_nok *= ok + nok

    total_nok -= total_ok

    if total_ok + total_nok == 1:
        translation = []
        for word in sentence:
            if len(OK[word]):
                translation.append(next(iter(OK[word])))
            else:
                translation.append(next(iter(NOK[word])))
        print(" ".join(translation))
        if total_ok:
            print("correct")
        else:
            print("incorrect")
    else:
        print(total_ok, "correct")
        print(total_nok, "incorrect")
