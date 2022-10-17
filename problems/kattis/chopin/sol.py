M = {
    "A#": "Bb",
    "C#": "Db",
    "D#": "Eb",
    "F#": "Gb",
    "G#": "Ab",
    "Bb": "A#",
    "Db": "C#",
    "Eb": "D#",
    "Gb": "F#",
    "Ab": "G#",
}
if __name__ == "__main__":
    key, tone = input().split()
    i = 1
    while key and tone:
        if key in M:
            print(f"Case {i}: {M[key]} {tone}")
        else:
            print(f"Case {i}: UNIQUE")

        try:
            key, tone = input().split()
        except EOFError:
            break

        i += 1
