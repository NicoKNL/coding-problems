import string

def match(plate, ref) -> bool:
    for c in plate:
        if plate.count(c) > ref.count(c):
            return False
    return True


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        plate = licensePlate.lower()
        plate = [c for c in plate if c in string.ascii_lowercase]
        plate = list(sorted(plate))

        length = 999
        best_word = ""
        for word in words:
            if match(plate, word):
                if len(word) < length:
                    length = len(word)
                    best_word = word
        
        return best_word
