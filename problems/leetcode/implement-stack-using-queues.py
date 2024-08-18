class MyStack:

    def __init__(self):
        self.i = 0
        self.Q = []

    def push(self, x: int) -> None:
        rev_queue = self.Q[self.i:][::-1]
        rev_queue.append(x)
        self.Q[self.i:] = rev_queue[::-1]

    def pop(self) -> int:
        item = self.Q[self.i]
        self.i += 1
        return item

    def top(self) -> int:
        return self.Q[self.i]

    def empty(self) -> bool:
        return self.i == len(self.Q)
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
