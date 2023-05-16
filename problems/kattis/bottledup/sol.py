def create_map(target, size):
    M = {}
    sum = 0
    while sum <= target:
        M[sum] = sum // size
        sum += size

    return M


if __name__ == "__main__":
    target, large, small = map(int, input().split())

    LARGE_MAP = create_map(target, large)
    SMALL_MAP = create_map(target, small)

    for volume, large_count in reversed(LARGE_MAP.items()):
        remainder = target - volume

        if remainder in SMALL_MAP:
            print(f"{large_count} {SMALL_MAP[remainder]}")
            exit(0)

    print("Impossible")
