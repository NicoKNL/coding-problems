if __name__ == "__main__":
    movement = input()
    up = movement.count("(")
    down = movement.count(")")
    print(up - down)
