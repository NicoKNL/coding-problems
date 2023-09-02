import sys
from copy import deepcopy

ORE = 0
CLAY = 1
OBSIDIAN = 2
GEODE = 3


class Recipe(object):
    def __init__(self, ore_cost, clay_cost, obsidian_cost, geode_cost):
        self.cost = {
            ORE: ore_cost,
            CLAY: clay_cost,
            OBSIDIAN: obsidian_cost,
            GEODE: geode_cost,
        }

    def __str__(self):
        return f"{self.cost}"


def cost(ore, clay, obsidian, geode):
    return [ore, clay, obsidian, geode]


def parseInput():
    recipes = []

    for line in sys.stdin:
        line = line.split(".")

        data = line[0].split()
        ore_cost = [int(data[-2]), 0, 0]

        data = line[1].split()
        clay_cost = [int(data[-2]), 0, 0]

        data = line[2].split()
        obsidian_cost = [int(data[-5]), int(data[-2]), 0]

        data = line[3].split()
        geode_cost = [int(data[-5]), 0, int(data[-2])]
        recipes.append(Recipe(ore_cost, clay_cost, obsidian_cost, geode_cost))

    return recipes


from time import sleep


def dfs(
    recipe, orebots, ore, claybots, clay, obsidianbots, obsidian, geodebots, geodes, t
):
    print("------")
    ore += orebots
    clay += claybots
    obsidian += obsidianbots
    geodes += geodebots
    print(f"bots: {orebots}, {claybots}, {obsidianbots}, {geodebots}")
    print(f"{t}: {ore}, {clay}, {obsidian}, {geodes}")
    sleep(1)

    if t == 15:
        return geodes

    options = []
    if ore >= recipe.cost[GEODE][ORE] and obsidian >= recipe.cost[GEODE][OBSIDIAN]:
        options.append(
            dfs(
                recipe,
                orebots,
                ore - recipe.cost[GEODE][ORE],
                claybots,
                clay,
                obsidianbots,
                obsidian - recipe.cost[GEODE][OBSIDIAN],
                geodebots + 1,
                geodes,
                t + 1,
            )
        )

    if ore >= recipe.cost[OBSIDIAN][ORE] and clay >= recipe.cost[OBSIDIAN][CLAY]:
        options.append(
            dfs(
                recipe,
                orebots,
                ore - recipe.cost[OBSIDIAN][ORE],
                claybots,
                clay - recipe.cost[OBSIDIAN][CLAY],
                obsidianbots + 1,
                obsidian,
                geodebots,
                geodes,
                t + 1,
            )
        )

    if ore >= recipe.cost[CLAY][ORE]:
        options.append(
            dfs(
                recipe,
                orebots,
                ore - recipe.cost[CLAY][ORE],
                claybots + 1,
                clay,
                obsidianbots,
                obsidian,
                geodebots,
                geodes,
                t + 1,
            )
        )

    if ore >= recipe.cost[ORE][ORE]:
        options.append(
            dfs(
                recipe,
                orebots + 1,
                ore - recipe.cost[ORE][ORE],
                claybots,
                clay,
                obsidianbots,
                obsidian,
                geodebots,
                geodes,
                t + 1,
            )
        )

    options.append(
        dfs(
            recipe,
            orebots,
            ore,
            claybots,
            clay,
            obsidianbots,
            obsidian,
            geodebots,
            geodes,
            t + 1,
        )
    )

    return max(options)


if __name__ == "__main__":
    RECIPES = parseInput()

    quality_level = 0
    for i, recipe in enumerate(RECIPES[:1]):
        print(recipe)
        BEST = 0
        quality_level += (i + 1) * dfs(recipe, 1, 0, 0, 0, 0, 0, 0, 0, 1)

    print(quality_level)
