import sys


def hash(s: str) -> int:
    value = 0
    for c in s:
        value += ord(c)
        value *= 17
        value %= 256
    return value


class Box:
    def __init__(self):
        self.lenses = dict()
        self.count = 0

    def add(self, label: str, focal_length: int) -> None:
        if label in self.lenses:
            index = self.lenses[label][0]
            self.lenses[label] = (index, focal_length)
        else:
            self.lenses[label] = (self.count, focal_length)
            self.count += 1

    def remove(self, label: str) -> None:
        if label in self.lenses:
            del self.lenses[label]

    def getFocalLengths(self) -> list[int]:
        data = list(self.lenses.values())
        data.sort(key=lambda x: x[0])
        focal_lengths = [x[1] for x in data]
        return focal_lengths

    def getFocusPower(self) -> int:
        total = 0
        for i, focus_length in enumerate(self.getFocalLengths(), 1):
            total += i * focus_length
        return total


def placeLenses(steps: list[str]) -> list[Box]:
    boxes = [Box() for _ in range(256)]

    for step in steps:
        if "=" in step:
            label, focal_length = step.split("=")

            box_id = hash(label)
            focal_length = int(focal_length)

            boxes[box_id].add(label, focal_length)
        else:
            label, _ = step.split("-")

            box_id = hash(label)
            boxes[box_id].remove(label)

    return boxes


steps = next(sys.stdin).strip().split(",")
boxes = placeLenses(steps)

total = 0

for i, box in enumerate(boxes, 1):
    total += i * box.getFocusPower()

print(total)
