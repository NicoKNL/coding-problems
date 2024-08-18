import sys

lines = [line.strip() for line in sys.stdin]


def isValidRoom(name, checksum):
    name = name.replace("-", "")
    chars = list(set(name))
    chars.sort()
    chars.sort(key=lambda c: name.count(c), reverse=True)
    namehash = "".join(chars[:5])
    return namehash == checksum


ABC = "abcdefghijklmnopqrstuvwxyz"


def decode(name, shift):
    real_name = ""

    for c in name:
        if c == "-":
            real_name += " "
        else:
            idx = ABC.index(c)
            idx += shift
            idx %= 26
            real_name += ABC[idx]

    return real_name


for line in lines:
    name, _, idchecksum = line.rpartition("-")
    ID = int(idchecksum[:3])
    checksum = idchecksum[-6:-1]
    if isValidRoom(name, checksum):
        real_name = decode(name, ID)
        if "north" in real_name:
            print(ID, real_name)
