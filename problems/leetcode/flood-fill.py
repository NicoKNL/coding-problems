from itertools import product

def adjacent(image: List[List[int]], row: int, col: int) -> List[List[int]]:
    adj = []
    offsets = [-1, 0, 1]
    
    for ro, co in product(offsets, offsets):
        if abs(ro) + abs(co) != 1:
            continue
        
        if 0 <= row + ro < len(image) and 0 <= col + co < len(image[0]):
            adj.append([row + ro, col + co])
    
    return adj

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        Q = [[sr, sc]]
        i = 0
        base = image[sr][sc]

        while i < len(Q):
            r, c = Q[i]
            i += 1

            image[r][c] = color
            for adj_r, adj_c in adjacent(image, r, c):
                if image[adj_r][adj_c] == base and not image[adj_r][adj_c] == color:
                    image[adj_r][adj_c] = color
                    Q.append([adj_r, adj_c])
        
        return image
