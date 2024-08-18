from collections import defaultdict

CHARS = "[]{}()"

n = int(input())

line = input()
line = [(i, c) for i, c in enumerate(line)]
line = [(i, c) for (i, c) in line if c in CHARS]

found = True
while found:
    found = False
    for i in range(len(line) - 1):
        open_ = line[i][1]
        close_ = line[i + 1][1]
        if (open_ == "[" and close_ == "]") or (open_ == "(" and close_ == ")") or (open_ == "{" and close_ == "}"):
            found = True
            line.pop(i + 1)
            line.pop(i)
            break
    
if line:
    for i, c in line:
        if c in ")}]":
            print(c, i)
            exit()

print("ok so far")

