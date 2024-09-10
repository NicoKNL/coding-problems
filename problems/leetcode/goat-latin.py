class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        result = []
        for i, word in enumerate(sentence.split(" "), 1):
            if word[0] in "aioueAIOUE":
                result.append(word + "ma" + "a" * i)
            else:
                result.append(word[1:] + word[0] + "ma" + "a" * i)
        
        return " ".join(result)
