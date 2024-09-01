class Solution:
    def judgeCircle(self, moves: str) -> bool:
        M = {
            "U": 0,
            "D": 0,
            "L": 0,
            "R": 0,
        }
        for move in moves:
            M[move] += 1
        return M["U"] == M["D"] and M["L"] == M["R"]
