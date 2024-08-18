class MyQueue:

    def __init__(self):
        self.S = []
        self.i = 0

    def push(self, x: int) -> None:
        self.S.append(x)

    def pop(self) -> int:
        item = self.S[self.i]
        self.i += 1
        return item

    def peek(self) -> int:
        return self.S[self.i]

    def empty(self) -> bool:
        return self.i == len(self.S)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
