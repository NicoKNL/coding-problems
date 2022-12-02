if __name__ == "__main__":
    n = int(input())

    topbottom = 0
    leftright = 0
    for _ in range(n):
        top, bottom, left, right = list(input())

        if top == "0":
            topbottom += 1
        if bottom == "0":
            topbottom += 1

        if left == "0":
            leftright += 1
        if right == "0":
            leftright += 1

    swords = 0
    while topbottom >= 2 and leftright >= 2:
        swords += 1
        topbottom -= 2
        leftright -= 2

    print(swords, topbottom, leftright)
