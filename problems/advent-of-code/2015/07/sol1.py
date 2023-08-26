from operator import add, and_, or_, invert, rshift, lshift

MASK16 = 2**16 - 1
NODES = dict()


class Node:
    def __init__(self, name, op, values, parents):
        self.name = name
        self.op = op
        self.parents = parents
        self.values = []

        self.signal = None
        self.children = []
        for v in values:
            self.processInput(v)

    def processInput(self, v):
        self.values.append(v)

        if (self.op == invert and len(self.values) == 1) or len(self.values) == 2:
            self._setSignal()

    def _setSignal(self):
        if self.op == lshift or self.op == rshift:
            self.values = self.values[::-1]
        self.signal = self.op(*self.values) & MASK16


def process(raw_values):
    ints = []
    parents = []

    for v in raw_values:
        try:
            ints.append(int(v))
        except:
            parents.append(v)

    return ints, parents


def createNode(s):
    s = s.replace(" ", "")
    s, name = s.split("->")

    op = None
    ints = None
    parents = None

    if "AND" in s:
        op = and_
        values = s.split("AND")

    elif "OR" in s:
        op = or_
        values = s.split("OR")

    elif "NOT" in s:
        op = invert
        values = [s.split("NOT")[-1]]

    elif "LSHIFT" in s:
        op = lshift
        values = s.split("LSHIFT")

    elif "RSHIFT" in s:
        op = rshift
        values = s.split("RSHIFT")

    else:
        op = add
        values = [0, s]

    ints, parents = process(values)
    NODES[name] = Node(name, op, ints, parents)


def createNodes():
    while True:
        try:
            createNode(input())
        except:
            break


def linkChildren():
    for node in NODES.values():
        for p in node.parents:
            NODES[p].children.append(node.name)


if __name__ == "__main__":
    createNodes()
    linkChildren()

    QUEUE = []
    for node in NODES.values():
        if node.signal != None:
            QUEUE.append(node)

    i = 0
    while i < len(QUEUE):
        node = QUEUE[i]
        for c in node.children:
            child = NODES[c]
            child.processInput(node.signal)
            if child.signal != None:
                QUEUE.append(child)
        i += 1

    print(NODES["a"].signal)
