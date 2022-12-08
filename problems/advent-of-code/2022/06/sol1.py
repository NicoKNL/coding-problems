if __name__ == "__main__":
    signal = input()

    for i in range(len(signal) - 4):
        if len(set(signal[i : i + 4])) == 4:
            print(i + 4)
            break
