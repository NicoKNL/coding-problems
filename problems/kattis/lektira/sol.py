if __name__ == "__main__":
    WORDS = []

    s = input()

    for i in range(1, len(s) - 1):
        for ii in range(i + 1, len(s)):
            a, b, c = s[:i], s[i:ii], s[ii:]
            WORDS.append(a[::-1] + b[::-1] + c[::-1])

    WORDS.sort()
    print(WORDS[0])
