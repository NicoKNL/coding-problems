if __name__ == "__main__":
    n = int(input())

    volume = 7
    for i in range(n):
        command = input()

        if command.endswith("op!"):
            volume = min(volume + 1, 10)
        else:
            volume = max(volume - 1, 0)

    print(volume)
