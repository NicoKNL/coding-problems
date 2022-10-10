if __name__ == "__main__":
    n = int(input())
    string_n = str(n)
    sorted_n = sorted(string_n)

    m = n

    while True:
        m += 1
        string_m = str(m)

        if len(string_m) > len(string_n):
            break

        sorted_m = sorted(string_m)

        if sorted_n == sorted_m:
            print(m)
            exit(0)

    print(0)
