import sys
from collections import Counter

lines = [line.strip() for line in sys.stdin]
rotated_lines = ["" for _ in range(len(lines[0]))]

for i in range(len(lines[0])):
    for line in lines:
        rotated_lines[i] += line[i]

ans = ""
for line in rotated_lines:
    counter = Counter(line)
    ans += counter.most_common(1)[0][0]

print(ans)
