if __name__ == "__main__":
    k = int(input())

    a = input()
    b = input()

    same = 0
    diff = 0

    for c1, c2 in zip(a, b):
        if c1 == c2:
            same += 1
        else:
            diff += 1

    possible_correct = min(k, same)
    k -= min(same, k)
    possible_correct += diff - k
    print(possible_correct)
