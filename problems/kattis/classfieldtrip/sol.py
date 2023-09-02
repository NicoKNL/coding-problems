if __name__ == "__main__":
    jack = input()
    jill = input()
    combined = list(jack + jill)
    combined.sort()
    print("".join(combined))
