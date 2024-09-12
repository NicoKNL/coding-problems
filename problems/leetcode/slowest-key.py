from itertools import pairwise

class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        times = [(x[1] - x[0], keysPressed[i]) for i, x in enumerate(pairwise([0] + releaseTimes))]
        longest = max(times)
        i = times.index(longest)
        return keysPressed[i]
