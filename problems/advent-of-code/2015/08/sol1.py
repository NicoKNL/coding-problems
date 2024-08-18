import sys

hex = "0123456789abcdef"
if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    total = sum([len(l) for l in lines])
    mem = 0

    for line in lines:
        line = list(line[1 : len(line) - 1])  # Remove first and last double quote
        print(line)
        i = 0
        count = 0
        while i < len(line):
            count += 1

            if line[i] == "\\":  # Note we have to use an escape char as well!
                if line[i + 1] == "\\" or line[i + 1] == '"':
                    i += 2
                else:  # \x00
                    i += 4

            else:
                i += 1

        mem += count

    print(total - mem)
