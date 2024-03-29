import sys

Pos = tuple[int, int]


def distance(a: Pos, b: Pos) -> int:
    """Manhattan distance"""
    return abs(b[0] - a[0]) + abs(b[1] - a[1])


def getRowOffsets(grid: list[str]) -> set[int]:
    offsets = [0]
    for r in range(ROWS):
        is_empty = True
        for c in range(COLS):
            if grid[r][c] == "#":
                is_empty = False
                break

        if is_empty:
            offsets.append(offsets[-1] + 1)
        else:
            offsets.append(offsets[-1])
    return offsets[1:]


def getColumnOffsets(grid: list[str]) -> set[int]:
    # rotate 90 degrees counter clockwise
    rotated_grid = [list(row) for row in zip(*grid)]
    return getRowOffsets(rotated_grid)


def getGalaxyPositions(
    grid: list[str], row_offsets: list[int], col_offsets: list[int]
) -> list[Pos]:
    positions = []

    for row in range(ROWS):
        for col in range(COLS):
            if grid[row][col] == "#":
                row_offset = row_offsets[row]
                col_offset = col_offsets[col]

                actual_position = (row + row_offset, col + col_offset)

                positions.append(actual_position)

    return positions


def computeTotalDistance(positions: list[Pos]) -> int:
    for i in range(len(positions)):
        for ii in range(i + 1, len(positions)):
            total_distance += distance(positions[i], positions[ii])


grid = [list(line.strip()) for line in sys.stdin]
ROWS = len(grid)
COLS = len(grid[0])

row_offsets = getRowOffsets(grid)
col_offsets = getColumnOffsets(grid)

positions = getGalaxyPositions(grid, row_offsets, col_offsets)
total_distance = computeTotalDistance(positions)

print(total_distance)
