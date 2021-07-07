def interpret(t):
    hours   = 0 
    minutes = (t[1] - t[0]) / 12 / pow(10, 9) / 60 
    seconds = (t[2] - t[0]) / 720 / pow(10, 9)
    nanoseconds = (seconds - int(seconds)) * pow(10, 9)

    return [str(int(x)) for x in [hours, minutes, seconds, nanoseconds]]


def solve():
    initial_time = [int(x) for x in input().split()] 
    return " ".join(interpret(initial_time))


if __name__ == "__main__":
    T = int(input())
    c = 1

    while T:
        print(f"Case #{c}: {solve()}")
        c += 1
        T -= 1
