import sys


def splitInput(lines):
    stack_data = []
    moves = []

    parsing_stack = True

    for line in lines:
        if not line:
            parsing_stack = False
            continue

        if parsing_stack:
            stack_data.append(line)
        else:
            moves.append(line)

    stack_count = int(stack_data[-1].split()[-1])

    return stack_count, stack_data[:-1], moves


def parseStacks(count, data):
    stacks = [[] for _ in range(count)]

    for row in data:
        print(row)
        for i, c in enumerate(range(1, len(row), 4)):
            if row[c].strip():
                stacks[i].append(row[c])
    stacks = [stack[::-1] for stack in stacks]
    return stacks


def parseMoves(moves):
    for i in range(len(moves)):
        words = moves[i].split()
        move = [words[1], words[3], words[5]]  # [count, from, to]
        move = list(map(int, move))
        move[1] -= 1  # Use 0 based indexing
        move[2] -= 1
        moves[i] = move


def execute(moves, stacks):
    for (count, s, t) in moves:
        for _ in range(count):
            stacks[t].append(stacks[s][-1])
            stacks[s] = stacks[s][:-1]


if __name__ == "__main__":
    lines = [l[:-1] for l in sys.stdin]

    stack_count, stack_data, moves = splitInput(lines)
    stacks = parseStacks(stack_count, stack_data)

    parseMoves(moves)
    execute(moves, stacks)

    answer = [" " for _ in range(stack_count)]

    for i, stack in enumerate(stacks):
        if stack:
            answer[i] = stack[-1]

    print("".join(answer))
