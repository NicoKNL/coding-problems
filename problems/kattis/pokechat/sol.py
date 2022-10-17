if __name__ == "__main__":
    S = input()
    code = input()
    print(
        "".join(
            [S[int(code[i : i + 3].lstrip("0")) - 1] for i in range(0, len(code), 3)]
        )
    )
