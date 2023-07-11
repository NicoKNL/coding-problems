if __name__ == "__main__":
    s, k = input().split()
    k = int(k)

    s = list(s)
    s_final = sorted(s)

    possible = True
    for i, letter in enumerate(s):
        if i < k and i >= (len(s) - k) and letter != s_final[i]:
            possible = False
            break

    if possible:
        print("Yes")
    else:
        print("No")
