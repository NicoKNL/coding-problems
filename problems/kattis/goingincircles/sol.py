if __name__ == "__main__":
    magic = "1100010101101010010100110111010111010111101010101001001101010111011"

    # Check for sequences which we fully overwrite
    sequence = []
    SAMPLE = len(magic)
    for i in range(SAMPLE):
        d = input()

        if d != magic[i]:
            print("? flip", flush=True)
            d = input()

        # sequence.append(d)

        print("? right", flush=True)

    for i in range(3 * SAMPLE):
        d = input()
        sequence.append(d)
        print("? right", flush=True)

    # for n in range(3, SAMPLE):
    # possible = True
    # s = set()
    # for i in range(0, 3 * SAMPLE, n):
    # s.add(sequence[i])
    # if len(s) > 1:
    # possible = False
    # break
    #
    # if possible:
    # print(f"! {n}")
    # exit()

    # Find longer sequences
    sequence = []
    count = 0
    while True:
        print("? right", flush=True)
        d = input()
        sequence.append(d)
        count += 1

        if len(sequence) > len(magic):
            sequence = sequence[1:]

        if str(sequence) == magic:
            print(count)
