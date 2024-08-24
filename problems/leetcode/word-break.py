class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        DP = [False for _ in range(len(s) + 1)]
        DP[0] = True
        for i in range(len(DP)):
            if not DP[i]:
                continue
            
            for word in wordDict:
                if s[i:].startswith(word):
                    DP[i + len(word)] = True
        
        return DP[-1]
