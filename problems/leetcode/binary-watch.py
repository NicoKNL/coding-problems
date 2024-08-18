from collections import defaultdict

def numberByBitCount(num: int, pad: bool) -> Dict[int, List[str]]:
    M = defaultdict(list)

    for i in range(num):
        bitcount = bin(i).count("1")
        if pad:
            M[bitcount].append(f"{i:02}")
        else:
            M[bitcount].append(f"{i}")
    
    return M

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        hours = numberByBitCount(12, False)
        minutes = numberByBitCount(60, True)

        solutions = []

        for i in range(turnedOn + 1):
            j = turnedOn - i
            for hour in hours[i]:
                for minute in minutes[j]:
                    solutions.append(f"{hour}:{minute}")
        
        return solutions
