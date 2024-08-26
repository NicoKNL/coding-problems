from collections import defaultdict
from itertools import combinations
from functools import reduce

ABC = "abcdefghijklmnopqrstuvwxyz"

def getWordScore(word: str, score: List[int]) -> int:
    return sum(score[ABC.index(c)] for c in word)

def getLetterCount(word: str) -> Dict[str, int]:
    COUNT = defaultdict(int)

    for c in word:
        COUNT[c] += 1
    
    return COUNT


def addDicts(d1: Dict[str, int], d2: Dict[str, int]) -> Dict[str, int]:
    result = dict()
    for k, v in d2.items():
        if k in d1:
            result[k] = v + d1[k]
        else:
            result[k] = v

    for k, v in d1.items():
        if k not in result:
            result[k] = v
    
    return result

def isValid(counter: Dict[str, int], limits: Dict[str, int]) -> bool:
    for k, v in counter.items():
        if k not in limits:
            return False

        if v > limits[k]:
            return False
    return True

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        best = 0
        letter_counts = getLetterCount("".join(letters))

        for k in range(1, len(words) + 1):
            for wordset in combinations(words, k):
                COUNT = reduce(lambda d1, d2: addDicts(d1, d2), (getLetterCount(w) for w in wordset))
                if isValid(COUNT, letter_counts):
                    best = max(best, sum(getWordScore(w, score) for w in wordset))
        
        return best
