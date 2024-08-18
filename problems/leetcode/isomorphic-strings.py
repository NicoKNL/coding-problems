from collections import defaultdict

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        A = defaultdict(list)
        for i, each in enumerate(s):
            A[each].append(i)

        B = defaultdict(list)
        for i, each in enumerate(t):
            B[each].append(i)

        return sorted(A.values()) == sorted(B.values())
