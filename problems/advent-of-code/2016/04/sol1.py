import sys

lines = [line.strip() for line in sys.stdin]


def isValidRoom(name, checksum):
    name = name.replace("-", "")
    chars = list(set(name))
    chars.sort()
    chars.sort(key=lambda c: name.count(c), reverse=True)
    namehash = "".join(chars[:5])
    return namehash == checksum


total = 0
for line in lines:
    name, _, idchecksum = line.rpartition("-")
    ID = int(idchecksum[:3])
    checksum = idchecksum[-6:-1]
    if isValidRoom(name, checksum):
        total += ID

print(total)
