from collections import defaultdict
from math import gcd

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        COUNT = defaultdict(int)
        for card in deck:
            COUNT[card] += 1

        smallest = min(COUNT.values())

        if smallest == 1:
            return False
        
        if gcd(*COUNT.values()) == 1:
            return False

        return True
