if __name__ == "__main__":
    people, events = map(int, input().split())

    WEALTH = dict()
    DEFAULT = 0

    for _ in range(events):
        event = input().split()

        if event[0] == "SET":
            who, what = map(int, event[1:])
            WEALTH[who] = what

        if event[0] == "PRINT":
            who = int(event[1])
            if who in WEALTH:
                print(WEALTH[who])
            else:
                print(DEFAULT)

        if event[0] == "RESTART":
            DEFAULT = int(event[1])
            WEALTH = dict()
