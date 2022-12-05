import sys

hex = "abcdef0123456789"
if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    total = sum([len(l) for l in lines])
    mem = 0

    for line in lines:
        line = list(line[1 : len(line) - 1])
        i = 0
        count = 0
        while i < len(line):
            count += 1

            if line[i] == "\\":
                if line[i + 1] == "\\" or line[i + 1] == '"':
                    i += 2
                elif line[i + 1] == "x" and line[i + 2] in hex and line[i + 3] in hex:
                    i += 4
                else:
                    i += 1
            else:
                i += 1

        mem += count

    print(total - mem)
