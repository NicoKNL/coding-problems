def split(s):
    segments = []
    seg = s[0]
    cur = ""
    for i in range(1, len(s)):
        if s[i] != seg[-1]:
            segments.append(seg)
            seg = s[i]
        else:
            seg += s[i]

    if seg:
        segments.append(seg)

    return segments


def convert(segment):
    token = segment[0]
    count = str(len(segment))
    return count + token


if __name__ == "__main__":
    s = input()

    for _ in range(50):
        segments = split(s)
        segments = [convert(s) for s in segments]
        s = "".join(segments)

    print(len(s))
