import sys

Pos = tuple[int, int]


def distance(a: Pos, b: Pos) -> int:
    """Manhattan distance"""
    return abs(b[0] - a[0]) + abs(b[1] - a[1])


def getRowOffsets(grid: list[str]) -> set[int]:
    empty_rows = [0]
    for r in range(ROWS):
        is_empty = True
        for c in range(COLS):
            if grid[r][c] == "#":
                is_empty = False
                break

        if is_empty:
            empty_rows.append(empty_rows[-1] + 999999)
        else:
            empty_rows.append(empty_rows[-1])
    return empty_rows[1:]


def getColumnOffsets(grid: list[str]) -> set[int]:
    # rotate 90 counter degrees clockwise
    rotated_grid = [list(row) for row in zip(*grid)]
    return getRowOffsets(rotated_grid)


def getGalaxyPositions(
    grid: list[str], empty_rows: list[int], empty_cols: list[int]
) -> list[Pos]:
    positions = []

    for row in range(ROWS):
        for col in range(COLS):
            if grid[row][col] == "#":
                row_offset = empty_rows[row]
                col_offset = empty_cols[col]

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

empty_rows = getRowOffsets(grid)
empty_cols = getColumnOffsets(grid)

positions = getGalaxyPositions(grid, empty_rows, empty_cols)
total_distance = computeTotalDistance(positions)

print(total_distance)
