class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        sorted_words = list(sorted(words, key=lambda word: tuple(order.index(c) for c in word)))
        return words == sorted_words
