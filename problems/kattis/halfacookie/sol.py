from math import acos, sqrt, pi


if __name__ == "__main__":
    while True:
        try:
            r, x, y = map(float, input().split())
        except:
            break

        if sqrt(x * x + y * y) > r:
            print("miss")
        else:
            area = pi * r * r

            h = r - sqrt(x * x + y * y)
            segment_area = r * r * acos(1 - h / r) - (r - h) * sqrt(
                r * r - pow(r - h, 2)
            )
            other_area = area - segment_area

            print(max(segment_area, other_area), min(segment_area, other_area))
