import sys
from collections import defaultdict
from pathlib import Path

SIZE = defaultdict(int)
VISIT_COUNT = defaultdict(int)
IS_DIR = defaultdict(bool)


def buildFileSystem(data):
    path = Path("/")
    IS_DIR[path] = True

    for line in data:
        if line.startswith("$ cd"):
            _, _, u = line.split()
            if u == "..":
                path = path.parent
            else:
                path = path / u
        elif line.startswith("$ ls"):
            continue
        elif line.startswith("dir"):
            _, dirname = line.split()
            p = path / dirname
            VISIT_COUNT[path] += 1
            IS_DIR[p] = True
        else:
            size, filename = line.split()
            p = path / filename
            SIZE[p] = int(size)
            VISIT_COUNT[path] += 1


def bfsFolderSize():
    Q = list(SIZE.keys())
    i = 0

    while i < len(Q):
        u = Q[i]
        if u.parent != u:
            parent = u.parent

            SIZE[parent] += SIZE[u]
            VISIT_COUNT[parent] -= 1

            if VISIT_COUNT[parent] == 0:
                Q.append(parent)

        i += 1


if __name__ == "__main__":
    data = [l.strip() for l in sys.stdin]

    buildFileSystem(data)
    bfsFolderSize()

    dir_sizes = [size for name, size in SIZE.items() if IS_DIR[name]]
    dir_sizes.sort()

    available_space = 70000000 - SIZE[Path("/")]

    for size in dir_sizes:
        if available_space + size >= 30000000:
            print(size)
            break
