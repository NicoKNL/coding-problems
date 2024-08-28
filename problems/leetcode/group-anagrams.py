from collections import defaultdict

def hash(s: str) -> str:
    return str(list(sorted(s)))

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            groups[hash(s)].append(s)

        return groups.values()
