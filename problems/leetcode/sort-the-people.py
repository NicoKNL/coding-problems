class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        sortedNames = list(zip(names, heights))
        sortedNames.sort(key=lambda person: person[1], reverse=True)
        return [x[0] for x in sortedNames]
