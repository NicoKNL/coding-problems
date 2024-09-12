from collections import defaultdict

class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        COUNT = defaultdict(int)

        for start, end in logs:
            for year in range(start, end):
                COUNT[year] += 1
        
        best = -1
        ans = -1

        for year, count in COUNT.items():
            if count > best:
                best = count
                ans = year
            elif count == best:
                ans = min(ans, year)
        return ans
