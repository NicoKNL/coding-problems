MINUTE = 60
HOUR = 60 * MINUTE
DAY = 24 * HOUR

def asTimestamp(s: str) -> int:
    hours, minutes = map(int, s.split(":"))
    return hours * HOUR + minutes * MINUTE
    

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timestamps = []
        for t in timePoints:
            timestamps.append(asTimestamp(t))

        timestamps.sort()
        timestamps.append(timestamps[0])
        delta = 15 * DAY
        for i in range(len(timestamps) - 1):
            a, b = timestamps[i], timestamps[i + 1]
            dt = max(a, b) - min(a, b)
            dt = min(DAY - dt, dt)
            delta = min(delta, dt)
        
        return delta // MINUTE
