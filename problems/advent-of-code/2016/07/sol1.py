import sys
import re

lines = [line.strip() for line in sys.stdin]

splitting_pattern = r"(\w+)|(\[\w+\])"
ABBA_pattern = r".*(.)(.)\2\1.*"

count = 0
for line in lines:
    matches = re.findall(splitting_pattern, line)
    parts = [m[0] if m[0] else m[1] for m in matches]

    has_TLS = False
    in_hypernet = False
    for part in parts:
        is_ABBA = re.findall(ABBA_pattern, part)
        if is_ABBA:
            is_ABBA = is_ABBA[0][0] != is_ABBA[0][1]

        if is_ABBA:
            has_TLS = True

        if part[0] == "[" and is_ABBA:
            in_hypernet = True
            break

    if has_TLS and not in_hypernet:
        count += 1
print(count)
