class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count = 0
        for word in words:
            if len(set(word) - set(allowed)) == 0:
                count += 1
        return count
