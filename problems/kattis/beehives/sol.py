from math import sqrt


def dist(x1, y1, x2, y2):
    dx = x1 - x2
    dy = y1 - y2
    return sqrt(dx * dx + dy * dy)


if __name__ == "__main__":
    while True:
        threshold, hives = map(float, input().split())
        hives = int(hives)

        if threshold == 0.0 and hives == 0:
            break

        HIVES = []
        for _ in range(hives):
            x, y = map(float, input().split())
            HIVES.append((x, y))

        SOUR = [False for _ in range(hives)]
        for u in range(hives):
            for v in range(hives):
                if u >= v:
                    continue

                if (
                    dist(HIVES[u][0], HIVES[u][1], HIVES[v][0], HIVES[v][1])
                    <= threshold
                ):
                    SOUR[u] = True
                    SOUR[v] = True

        sour = sum(SOUR)
        sweet = hives - sour

        print(f"{sour} sour, {sweet} sweet")
