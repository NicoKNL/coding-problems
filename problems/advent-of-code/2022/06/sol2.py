if __name__ == "__main__":
    signal = input()

    for i in range(len(signal) - 14):
        if len(set(signal[i : i + 14])) == 14:
            print(i + 14)
            break
