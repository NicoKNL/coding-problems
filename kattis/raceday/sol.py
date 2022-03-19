class Runner:
    def __init__(self, firstname, lastname, bib):
        self.name = f"{lastname}, {firstname}"
        self.bib = int(bib)
        self.bibstring = bib
        self.splits = {
            "S1": "",
            "S2": "",
            "F": "",
        }
        self.ranks = {
            "S1": "0",
            "S2": "0",
            "F": "0",
        }

    def print_runner(self):
        f_name = self.name.ljust(20)
        f_bib = self.bibstring.rjust(10)
        f_S1 = self.splits["S1"].rjust(10)
        f_S1_rank = self.ranks["S1"].rjust(10)
        f_S2 = self.splits["S2"].rjust(10)
        f_S2_rank = self.ranks["S2"].rjust(10)
        f_F = self.splits["F"].rjust(10)
        f_F_rank = self.ranks["F"].rjust(10)

        print(f"{f_name}{f_bib}{f_S1}{f_S1_rank}{f_S2}{f_S2_rank}{f_F}{f_F_rank}")

    def add_time(self, split, time):
        self.splits[split] = time


class Table:
    def __init__(self):
        self.runners = dict()

    def add_runner(self, runner):
        self.runners[runner.bib] = runner

    def add_time(self, bib, split, time):
        self.runners[int(bib)].add_time(split, time)

    def order_bibs(self):
        bibs_and_names = [(self.runners[bib].name, bib) for bib in self.runners.keys()]
        return sorted(bibs_and_names)

    def calculate_ranks_for_split(self, split):
        times = sorted(
            [(self.runners[bib].splits[split], bib) for bib in self.runners.keys()]
        )

        rank = 1
        players = 1
        prev_time = None
        for player_time in times:
            t = player_time[0]
            bib = player_time[1]

            if not prev_time:
                prev_time = t

            if prev_time != t:
                rank = players

            self.runners[bib].ranks[split] = str(rank)
            players += 1
            prev_time = t

    def calculate_ranks(self):
        self.calculate_ranks_for_split("S1")
        self.calculate_ranks_for_split("S2")
        self.calculate_ranks_for_split("F")

    def print_header(self):
        print(
            "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK"
        )

    def print_runners(self):
        bibs = self.order_bibs()

        for _, bib in bibs:
            self.runners[bib].print_runner()

    def print_table(self):
        self.print_header()
        self.print_runners()
        print("")


def solve(n):
    table = Table()

    for i in range(n):
        data = input().split()
        runner = Runner(*data)

        table.add_runner(runner)

    for i in range(3 * n):
        data = input().split()
        table.add_time(*data)

    table.calculate_ranks()
    table.print_table()


if __name__ == "__main__":
    while True:
        n = int(input())

        if n == 0:
            break

        solve(n)
