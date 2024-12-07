import sys
import re

lines = [line.strip() for line in sys.stdin]

splitting_pattern = r"(\w+)|(\[\w+\])"
ABA_pattern = r"(?=(\w)(.)(\1))"

count = 0
for line in lines:
    matches = re.findall(splitting_pattern, line)
    parts = [m[0] if m[0] else m[1] for m in matches]

    ABAs = []
    valid = False
    for part in sorted(parts, reverse=True):
        if part[0] == "[":
            if not ABAs:
                break
            for ABA in ABAs:
                BAB_pattern = rf".*{ABA[1]}{ABA[0]}{ABA[1]}.*"
                BAB = re.findall(BAB_pattern, part)
                if BAB:
                    valid = True
                    break
        else:
            ABA = re.finditer(ABA_pattern, part)
            if ABA:
                for each in ABA:
                    if len(set(each.groups())) == 2:
                        ABAs.append(each.groups())

    if valid:
        count += 1

print(count)
