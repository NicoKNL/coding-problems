class TrafficLight:
    def __init__(self, red, green):
        self.state = "R"
        self.t = 0
        self.red = red
        self.green = green

    def advance(self):
        self.t += 1
        if self.state == "R" and self.t == self.red:
            self.state = "G"
            self.t = 0
        elif self.state == "G" and self.t == self.green:
            self.state = "R"
            self.t = 0


if __name__ == "__main__":
    N, L = map(int, input().split())

    distances = []
    lights = []

    for _ in range(N):
        D, R, G = map(int, input().split())
        distances.append(D)
        lights.append(TrafficLight(R, G))

    dist = 0
    i = 0
    t = 1

    while dist < L:
        for light in lights:
            light.advance()
        t += 1

        if i >= len(distances):
            dist += 1
        elif dist < distances[i]:
            dist += 1
        elif dist == distances[i] and lights[i].state == "G":
            dist += 1
            i += 1
    print(t)
