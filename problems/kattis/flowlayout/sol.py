if __name__ == "__main__":
    while True:
        WIDTH = int(input())
        if WIDTH == 0:
            break

        base = 0
        current_width = 0
        max_height = 0
        max_width = 0
        while True:
            w, h = map(int, input().split())
            if w == -1 and h == -1:
                break

            if current_width + w > WIDTH:
                base = max_height
                current_width = 0

            current_width += w
            max_width = max(max_width, current_width)
            max_height = max(max_height, base + h)

        print(f"{max_width} x {max_height}")
