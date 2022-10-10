from enum import Enum


class State(Enum):
    FIST = 0
    HAND = 1
    PALM = 2


def solve():
    s, n = map(int, input().split())

    gamestate = [(State.FIST, i + 1) for i in range(n)]

    i = 0
    while len(gamestate) > 1:
        i = (i + s - 1) % len(gamestate)

        gs = gamestate[i][0]
        player = gamestate[i][1]

        if gs == State.FIST:
            gamestate.pop(i)
            gamestate.insert(i, (State.HAND, player))
            gamestate.insert(i, (State.HAND, player))
        elif gs == State.HAND:
            gamestate[i] = (State.PALM, player)
            i = (i + 1) % len(gamestate)
        elif gs == State.PALM:
            gamestate.pop(i)

    print(gamestate[0][1])


if __name__ == "__main__":
    solve()
