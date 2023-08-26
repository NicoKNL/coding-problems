def _stringToNumbers(s):
    return [ord(c) for c in s]


def _numbersToString(nums):
    return "".join([chr(n) for n in nums])


class Password:
    def __init__(self, password):
        self.password = _stringToNumbers(password)
        self._INVALID = [ord("i"), ord("o"), ord("l")]

    def __iter__(self):
        return self

    def __next__(self):
        while True:
            self._increment()
            if self._isValid():
                return _numbersToString(self.password)

    def _increment(self):
        for i in range(len(self.password) - 1, -1, -1):
            self.password[i] += 1
            if self.password[i] - ord("a") < 26:
                break
            else:
                self.password[i] = ord("a")

    def _isValid(self):
        return (
            self._hasAStraight()
            and self._hasOnlyGoodChars()
            and self._containsTwoPairs()
        )

    def _hasAStraight(self):
        for i in range(len(self.password) - 2):
            if (
                self.password[i + 1] - self.password[i] == 1
                and self.password[i + 2] - self.password[i + 1] == 1
            ):
                return True

        return False

    def _hasOnlyGoodChars(self):
        for each in self.password:
            if each in self._INVALID:
                return False
        return True

    def _containsTwoPairs(self):
        pairs = set()

        for i in range(len(self.password) - 1):
            if self.password[i] == self.password[i + 1]:
                pairs.add(self.password[i])

        return len(pairs) >= 2


if __name__ == "__main__":
    s = input()
    password = Password(s)
    print(next(password))
