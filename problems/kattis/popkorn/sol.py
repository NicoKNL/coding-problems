if __name__ == "__main__":
    n = int(input())

    teamsize = n // 4
    popkorn = 4 * teamsize * (teamsize - 1) // 2
    popkorn += 2 + 1 + 1
    print(popkorn)
