class Solution:
    def validStrings(self, n: int) -> List[str]:
        result = []
        for i in range(2 ** 18 + 1):
            b = bin(i)[2:].rjust(n, "0")

            if len(b) > n:
                break

            if "00" not in b:
                result.append(b)

        return result
