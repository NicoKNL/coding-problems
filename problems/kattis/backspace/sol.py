if __name__ == "__main__":
    s = input()
    correct = []

    for c in s:
        if c == "<":
            correct.pop()
        else:
            correct.append(c)

    print("".join(correct))
