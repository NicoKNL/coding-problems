from collections import defaultdict

class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        COUNTERS = [defaultdict(int) for _ in range(n)]
        winning = [False for _ in range(n)]

        for player, color in pick:
            COUNTERS[player][color] += 1
            if COUNTERS[player][color] > player:
                winning[player] = True
        
        return sum(winning)
