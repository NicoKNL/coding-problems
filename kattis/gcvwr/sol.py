if __name__ == "__main__":
    G, T, N = map(int, input().split())
    weights = map(int, input().split())

    total_weight = sum(weights)

    print(int((G - T) * 0.9 - total_weight))
