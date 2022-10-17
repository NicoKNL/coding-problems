ABC = "x!\"#$%&'()*+,-./"
AZ = "abcdefghijklmnopqrstuvwxyz"
AZ = 1000 * AZ


def rune_value(rune):
    return sum([ABC.index(x) for x in rune])


def translate(rune, key, val):
    value = rune_value(rune)
    return AZ[value + AZ.index(val) - rune_value(key)]


if __name__ == "__main__":
    key, val = input().split()

    while True:
        try:
            s = input().split()
        except:
            break
        translation = ""

        for rune in s:
            if rune == "0":
                translation += " "
            elif rune == ">":
                translation += "."
            elif rune == "<":
                translation += ","
            elif rune == key:
                translation += val
            else:
                translation += translate(rune, key, val)

        print(translation)
