if __name__ == "__main__":
    n, p, x, y = map(int, input().split())

    meowth_pages = p // (n - 1)
    my_pages = p

    if n % p == 0:
        meowth_pages += 1

    print(meowth_pages * y + my_pages * x)
