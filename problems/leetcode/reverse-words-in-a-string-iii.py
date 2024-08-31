class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(" ")
        words = [w[::-1] for w in words]
        return " ".join(words)
