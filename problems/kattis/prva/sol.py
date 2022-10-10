def get_words_from_grid(G):
    words = []

    for row in G:
        row = "".join(row)
        row = row.split("#")
        words.extend([w for w in row if len(w) > 1])

    return words


if __name__ == "__main__":
    r, c = map(int, input().split())

    grid_hor = [list(input()) for i in range(r)]
    grid_ver = list(reversed(list(zip(*grid_hor))))

    words = []

    words.extend(get_words_from_grid(grid_hor))
    words.extend(get_words_from_grid(grid_ver))

    words = sorted(words)

    print(words[0])
