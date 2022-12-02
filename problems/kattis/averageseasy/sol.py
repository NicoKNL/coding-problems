if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        _ = input()
        _, __ = input().split()
        cs = list(map(int, input().split()))
        ec = list(map(int, input().split()))
        cs_avg = sum(cs) / len(cs)
        ec_avg = sum(ec) / len(ec)

        count = 0
        for student in cs:
            if student < cs_avg and student > ec_avg:
                count += 1

        print(count)
