class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return list(sorted(score, key=lambda student: student[k], reverse=True))
