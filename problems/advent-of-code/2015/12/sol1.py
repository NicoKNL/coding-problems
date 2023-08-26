if __name__ == "__main__":
    s = input()

    chars = [",", "[", "]", '"', ":", "{", "}"]
    for c in chars:
        s = s.replace(c, " ")

    items = [elem for elem in s.split(" ") if elem]
    print(items)

    result = 0
    for item in items:
        try:
            item = int(item)
            result += item
        except:
            pass

    print(result)
