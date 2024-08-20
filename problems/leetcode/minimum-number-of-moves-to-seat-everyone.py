class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats = sorted(seats)
        students = sorted(students)

        total = 0
        for (seat, student) in zip(seats, students):
            total += abs(student - seat)

        return total
