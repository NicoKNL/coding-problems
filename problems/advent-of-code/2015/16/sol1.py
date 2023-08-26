import sys


class Aunt:
    def __init__(self, s):
        s = s.partition(":")
        self.name = s[0]
        self.props = dict()

        for each in s[-1].split(","):
            k, v = each.split(":")
            self.props[k.strip()] = int(v)

        self.candidate = True


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    aunts = [Aunt(s) for s in lines]

    ticker = {
        "children": 3,
        "cats": 7,
        "samoyeds": 2,
        "pomeranians": 3,
        "akitas": 0,
        "vizslas": 0,
        "goldfish": 5,
        "trees": 3,
        "cars": 2,
        "perfumes": 1,
    }

    for k, v in ticker.items():
        for aunt in aunts:
            if k in aunt.props:
                if aunt.props[k] != v:
                    aunt.candidate = False

    for aunt in aunts:
        if aunt.candidate:
            print(aunt.name)
