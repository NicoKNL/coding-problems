if __name__ == "__main__":
    movement = input()

    floor = 0
    for i, direction in enumerate(movement):
        if direction == "(":
            floor += 1
        else:
            floor -= 1

        if floor == -1:
            break

    print(i + 1)
