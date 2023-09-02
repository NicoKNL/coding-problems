HAPPY = ":)"
SAD = ":("

if __name__ == "__main__":
    s = input()
    happy_count = 0
    sad_count = 0

    for i in range(len(s) - 1):
        chars = s[i : i + 2]
        if chars == HAPPY:
            happy_count += 1
        elif chars == SAD:
            sad_count += 1

    if happy_count and not sad_count:
        print("alive")
    elif not happy_count and sad_count:
        print("undead")
    elif happy_count and sad_count:
        print("double agent")
    else:
        print("machine")
