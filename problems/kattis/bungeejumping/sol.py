TIMESTEP = 0.001


def solve(strength, length, height, weight):
    if weight == 0:
        print("Stuck in the air.")
        return

    if height == 0:
        print("James Bond survives.")

    dist = 0.0
    v = 0.0
    t = 0.0

    while True:
        t += TIMESTEP

        f1 = 9.81 * weight
        f2 = 0
        if dist >= length:
            f2 = strength * (dist - length)

        f = f1 - f2

        if weight > 0:
            a = f / weight

        v += a * TIMESTEP
        dist += v * TIMESTEP

        if dist >= height:
            if v > 10.0:
                print("Killed by the impact.")
            else:
                print("James Bond survives.")

            return

        if v < 0:
            print("Stuck in the air.")
            return


if __name__ == "__main__":
    while True:
        k, l, s, w = map(float, input().split())

        if k == 0 and l == 0 and s == 0 and w == 0:
            break

        solve(k, l, s, w)
