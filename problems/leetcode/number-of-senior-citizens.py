class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count = 0
        for senior in details:
            age = int(senior[11:13])
            if age > 60:
                count += 1
        return count
