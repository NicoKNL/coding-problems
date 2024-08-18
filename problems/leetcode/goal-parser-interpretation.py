MAP = {
    "G": "G",
    "()": "o",
    "(al)": "al"
}

class Solution:
    def interpret(self, command: str) -> str:
        result = ""

        while command:
            for opt in MAP.keys():
                if command.startswith(opt):
                    command = command[len(opt):] 
                    result += MAP[opt]
                    break

        return result
