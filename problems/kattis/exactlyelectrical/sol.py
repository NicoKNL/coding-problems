if __name__ == "__main__":
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())

    n = int(input())

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    n -= dx
    n -= dy

    if n < 0 or n % 2 != 0:
        print("N")
    else:
        print("Y")
