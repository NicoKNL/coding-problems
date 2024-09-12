class Solution:
    def sortSentence(self, s: str) -> str:
        words = []
        for word in s.split(" "):
            index = int(word[-1])
            words.append((index, word[:-1]))
        words.sort()
        return " ".join(word[1] for word in words)
