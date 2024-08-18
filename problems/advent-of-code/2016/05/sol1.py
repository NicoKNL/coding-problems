from hashlib import md5

if __name__ == "__main__":
    secret = "ugkcyxxp"
    password = ""
    i = 0

    while len(password) < 8:
        code = f"{secret}{i}".encode()
        hexvalue = md5(code).hexdigest()

        if hexvalue.startswith("00000"):
            print(hexvalue)
            password += hexvalue[5]

        i += 1

    print(password)
