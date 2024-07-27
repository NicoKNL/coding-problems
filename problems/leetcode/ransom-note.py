from collections import defaultdict


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        letters = defaultdict(int)

        for letter in magazine:
            letters[letter] += 1

        for letter in ransomNote:
            letters[letter] -= 1

            if letters[letter] < 0:
                return False

        return True
