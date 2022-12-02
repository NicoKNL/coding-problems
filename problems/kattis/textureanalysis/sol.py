if __name__ == "__main__":
    T = 0

    while True:
        T += 1
        s = input()
        if s == "END":
            break

        sections = s.split("*")
        if s[0] == "*":
            sections = sections[1:]
        if s[-1] == "*":
            sections = sections[:-1]

        if sections:
            target = len(sections[0])

        is_even = True
        for section in sections:
            if len(section) != target:
                is_even = False
                break

        if is_even:
            print(f"{T} EVEN")
        else:
            print(f"{T} NOT EVEN")
