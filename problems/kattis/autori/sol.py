#! /usr/bin/python3

if __name__ == "__main__":
    s = input().split("-")

    result = ""
    for word in s:
        result += word[0]

    print(result)
