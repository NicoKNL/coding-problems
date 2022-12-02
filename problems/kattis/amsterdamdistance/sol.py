from math import pi

if __name__ == "__main__":
    m, n, r = map(float, input().split())

    ax, ay, bx, by = map(int, input().split())

    best = 1e9
    for i in range(max(ay, by) + 1):
        down_and_up = abs(ay - i) * r / n + abs(by - i) * r / n
        angle = abs(ax - bx) / m
        radius = i * r / n
        circle_segment = pi * angle * radius
        best = min(down_and_up + circle_segment, best)

    print(best)
