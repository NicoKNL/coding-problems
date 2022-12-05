from hashlib import md5

if __name__ == "__main__":
    secret = "bgvyzdsv"
    i = 1

    while True:
        code = f"{secret}{i}".encode()
        if md5(code).hexdigest().startswith("000000"):
            break

        i += 1

    print(i)
