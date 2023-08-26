import json


def recursiveSum(data):
    result = 0

    if type(data) == int:
        result = data
    elif type(data) == list:
        for each in data:
            result += recursiveSum(each)
    elif type(data) == dict:
        for k, v in data.items():
            if v == "red":
                return 0
            result += recursiveSum(v)

    return result


if __name__ == "__main__":
    s = input()
    data = json.loads(s)
    print(recursiveSum(data))
