if __name__ == "__main__":
    n = int(input())

    if n % 2 == 0 and (n // 2) % 2 == 0:
        print("Even")
    elif n % 2 == 0 and (n // 2) % 2 == 1:
        print("Odd")
    else:  # n % 2 == 1:
        print("Either")
