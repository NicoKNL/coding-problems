class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groupSizes = sorted((size, i) for i, size in enumerate(groupSizes))

        result = []
        group = []
        for size, i in groupSizes:
            group.append(i)

            if len(group) == size:
                result.append(group)
                group = []
        
        return result
