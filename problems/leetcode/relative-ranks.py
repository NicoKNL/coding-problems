class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        scores = [(s, i) for i, s in enumerate(score)]
        scores.sort(reverse=True)
        
        for i in range(len(scores)):
            if i == 0:
                result = "Gold Medal"
            elif i == 1:
                result = "Silver Medal"
            elif i == 2:
                result = "Bronze Medal"
            else:
                result = str(i + 1)

            scores[i] = (scores[i], result)
        
        scores.sort(key=lambda x: x[0][1])
        
        return [s[1] for s in scores]
