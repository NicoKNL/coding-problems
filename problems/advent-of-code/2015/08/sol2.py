import sys

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    total = sum([len(l) for l in lines])
    new_total = 0

    for line in lines:
        newline = []
        i = 0
        while i < len(line):
            if line[i] == "\\":
                newline.append("\\")
                newline.append("\\")
            elif line[i] == '"':
                newline.append("\\")
                newline.append('"')
            else:
                newline.append(line[i])
            i += 1

        new_total += len(newline) + 2

    print(new_total - total)
