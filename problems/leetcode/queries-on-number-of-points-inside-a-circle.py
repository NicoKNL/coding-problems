def inCircle(x: int, y: int, radius: int, u: int, v: int) -> bool:
    dx = u - x
    dy = v - y
    dist = sqrt(dx * dx + dy * dy)
    return dist <= radius


class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        result = []

        for x, y, r in queries:
            count = 0
            for u, v in points:
                count += inCircle(x, y, r, u, v)
            result.append(count)
        
        return result
