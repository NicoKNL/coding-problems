from math import atan, sqrt, degrees

if __name__ == "__main__":
    while True:
        a, b, s, m, n = map(int, input().split())

        if a == 0 and b == 0 and s == 0 and m == 0 and n == 0:
            break

        start = (0.0, 0.0)
        end = (m * a, n * b)

        angle = degrees(atan(end[1] / end[0]))
        speed = sqrt(pow(end[0], 2) + pow(end[1], 2)) / s
        print(f"{angle:.2f} {speed:.2f}")
