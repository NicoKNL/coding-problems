from random import randint

class RandomizedSet:
    def __init__(self):
        self.store = [0 for _ in range(int(2 * 10e5))]
        self.start = 0
        self.end = 0
        self.tracker = dict()

    def insert(self, val: int) -> bool:
        if val in self.tracker:
            return False
        
        self.store[self.end] = val
        self.tracker[val] = self.end
        self.end += 1

        return True

    def remove(self, val: int) -> bool:
        if val in self.tracker:
            loc = self.tracker[val]
            self.store[self.start], self.store[loc] = self.store[loc], self.store[self.start]
            self.tracker[self.store[loc]] = loc
            del self.tracker[val]
            self.start += 1
            return True
        return False

    def getRandom(self) -> int:
        idx = randint(self.start, self.end - 1)
        return self.store[idx]

        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
