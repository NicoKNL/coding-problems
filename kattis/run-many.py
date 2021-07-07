import os

os.system("python3 stretching-gen.py")

for f in os.listdir("."):
    if f.startswith("input") and f.endswith(".txt"):
        # print("f: ", f)
        os.system(f"python3 stretching.py < {f}")