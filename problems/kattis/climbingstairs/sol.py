if __name__ == "__main__":
    steps, desk, office = map(int, input().split())

    total_steps = 0
    if office <= desk:
        total_steps += desk
        while total_steps < steps:
            total_steps += 2
        total_steps += desk
    else:
        total_steps += office
        total_steps += office - desk
        while total_steps < steps:
            total_steps += 2
        total_steps += desk

    print(total_steps)
