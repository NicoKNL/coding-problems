class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.i = 0
        

    def visit(self, url: str) -> None:
        self.history = self.history[:self.i + 1]
        self.history.append(url)
        self.i += 1

    def back(self, steps: int) -> str:
        self.i -= steps
        self.i = max(self.i, 0)
        return self.history[self.i]
        

    def forward(self, steps: int) -> str:
        self.i += steps
        self.i = min(len(self.history) - 1, self.i)
        return self.history[self.i]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
