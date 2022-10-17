if __name__ == "__main__":
    s = input().split()

    words = len(s)
    ae_count = sum([("ae" in w) for w in s])

    if ae_count / words >= 0.4:
        print("dae ae ju traeligt va")
    else:
        print("haer talar vi rikssvenska")
