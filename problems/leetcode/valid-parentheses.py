SYMBOLS = ["()", "{}", "[]"]


class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False

        while s:
            found = False
            for symbol in SYMBOLS:
                if symbol in s:
                    s = s.replace(symbol, "")
                    found = True

            if not found:
                return False

        return True
