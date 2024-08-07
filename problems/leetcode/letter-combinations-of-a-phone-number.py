class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
            
        KEYS = {
            "2": "abc", 
            "3": "def", 
            "4": "ghi", 
            "5":"jkl",
            "6":"mno", 
            "7":"pqrs", 
            "8":"tuv", 
            "9":"wxyz",
        }
        Q = [(digits, "")]
        i = 0

        result = []

        while i < len(Q):
            digits, word = Q[i]
            i += 1

            if not digits:
                result.append(word)
                continue

            for letter in KEYS[digits[0]]:
                Q.append((digits[1:], word + letter))

        return result
