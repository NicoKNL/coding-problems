import sys

REGISTERS = {"a": 0, "b": 0}

if __name__ == "__main__":
    instructions = [l.strip().replace(",", "").split(" ") for l in sys.stdin]

    ip = 0
    while ip >= 0 and ip < len(instructions):
        instr = instructions[ip]
        op = instr[0]
        if op == "hlf":
            r = instr[1]
            REGISTERS[r] = REGISTERS[r] >> 1
        elif op == "tpl":
            r = instr[1]
            value = REGISTERS[r]
            REGISTERS[r] = REGISTERS[r] << 1
            REGISTERS[r] += value
        elif op == "inc":
            r = instr[1]
            REGISTERS[r] += 1
        elif op == "jmp":
            offset = int(instr[1])
            ip += offset
            continue
        elif op == "jie":
            r = instr[1]
            if REGISTERS[r] % 2 == 0:
                offset = int(instr[2])
                ip += offset
                continue
        elif op == "jio":
            r = instr[1]
            if REGISTERS[r] == 1:
                offset = int(instr[2])
                ip += offset
                continue
        ip += 1

    print(REGISTERS["b"])
