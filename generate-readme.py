INTRODUCTION = """# Coding Problems
This repository contains my solutions for various competitive programming problems.

Note: Not all source code offers a valid solution (yet). Most code does.
"""

from pathlib import Path
import re

ROOTS = {
    "advent-of-code": Path("./problems/advent-of-code"),
    "codechef": Path("./problems/codechef"),
    "kattis": Path("./problems/kattis"),
}
LANGUAGES = ["cpp", "py", "go"]


def markdownRow(cells):
    return "|" + "|".join(map(str, cells)) + "|"


class Problem:
    def __init__(self, location: Path):
        self.title = location.parts[-2]
        self.language = location.suffix
        self.location = location
        self.header = ["day", "language", "location"]

        self.language_icon = ""
        if self.language == ".py":
            self.language_icon = "<img src='.github/icons/python.svg' width='24' height='24' style='max-width: 24px'>"
        elif self.language == ".cpp":
            self.language_icon = (
                "<img src='.github/icons/c++.svg' width='24' height='24'>"
            )
        elif self.language == ".go":
            self.language_icon = "<img src='.github/icons/go.svg' width='24' height='24' style='max-width: 24px'>"

    def getHeader(self):
        return markdownRow(self.header)

    def __str__(self):
        return markdownRow(
            [
                self.title,
                self.language,
                f"[{self.language_icon}]({self.location})",
            ]
        )


class AdventOfCodeProblem(Problem):
    def __init__(self, location1: Path, location2: Path):
        super().__init__(location1)
        self.location1 = f"<a href={location1.parents[0]}>{self.language_icon}</a>"
        self.year = location1.parts[-3]
        self.day = location1.parts[-2]
        self.url = f"https://adventofcode.com/{self.year}/day/{self.day.lstrip('0')}"
        self.header = ["year", "day", "part1", "part2", "url"]

    def getHeader(self):
        return markdownRow(self.header)

    def __str__(self):
        return markdownRow(
            [
                self.year,
                self.day,
                self.location1,
                self.location2,
                f"[<img src='https://adventofcode.com/favicon.png' width='24' height='24'>]({self.url})",
            ]
        )


class CodeChefProblem(Problem):
    def __init__(self, location: Path):
        super().__init__(location)
        self.url = f"https://www.codechef.com/submit/{self.title}"
        self.header = ["title", "solution", "url"]

    def getHeader(self):
        return markdownRow(self.header)

    def __str__(self):
        return markdownRow(
            [
                self.title,
                f"[{self.language_icon}]({self.location})",
                f"[![CodeChef](https://cdn.codechef.com/favicon.ico)]({self.url})",
            ]
        )


class KattisProblem(Problem):
    def __init__(self, location: Path):
        super().__init__(location)
        self.url = f"https://open.kattis.com/problems/{self.title}"
        self.header = ["title", "solution", "url"]

    def getHeader(self):
        return markdownRow(self.header)

    def __str__(self):
        return markdownRow(
            [
                self.title,
                f"[{self.language_icon}]({self.location})",
                f"[![Kattis](https://open.kattis.com/favicon)]({self.url})",
            ]
        )


def collectProblemsWithRoot(root: Path):
    problems = []
    for language in LANGUAGES:
        problems_in_language = root.glob(f"**/*.{language}")
        problems.extend([Problem(p) for p in problems_in_language])

    problems.sort(key=lambda p: p.title)
    return problems


def collectKattisProblems():
    problems = []
    for language in LANGUAGES:
        problems_in_language = ROOTS["kattis"].glob(f"*/*.{language}")
        problems.extend([KattisProblem(p) for p in problems_in_language])

    problems.sort(key=lambda p: p.title)
    return problems


def collectCodeChefProblems():
    problems = []
    for language in LANGUAGES:
        problems_in_language = ROOTS["codechef"].glob(f"*/*.{language}")
        problems.extend([CodeChefProblem(p) for p in problems_in_language])

    problems.sort(key=lambda p: p.title)
    return problems


def collectAdventOfCodeProblems():
    problems = []
    for language in LANGUAGES:
        problems_in_language = ROOTS["advent-of-code"].glob(f"**/*.{language}")
        grouped_problems = {}
        for p in problems_in_language:
            root = p.parent
            if root not in grouped_problems:
                grouped_problems[root] = [p]
            else:
                grouped_problems[root].append(p)

        for key, value in grouped_problems.items():
            if len(value) == 1:
                grouped_problems[key].append(None)
            else:
                grouped_problems[key].sort()

        problems.extend([AdventOfCodeProblem(*v) for k, v in grouped_problems.items()])

    problems.sort(key=lambda p: int(p.year + p.day))
    return problems


def collectProblems():
    return {
        "advent-of-code": collectAdventOfCodeProblems(),
        "codechef": collectCodeChefProblems(),
        "kattis": collectKattisProblems(),
    }


def problemsAsTable(section, problems):
    SECTION = f"# {section}"
    HEADER = problems[0].getHeader()
    DIVIDER = re.sub("[a-z]", "-", HEADER)
    DIVIDER = re.sub("[0-9]", "-", DIVIDER)

    table = [SECTION, HEADER, DIVIDER]
    for p in problems:
        table.append(str(p))

    return "\n".join(table)


def generateAdventOfCodeTable(problems):
    SECTION = "# Advent of Code"

    years = list(set([p.year for p in problems]))
    years.sort()

    problem_table = [["" for _ in range(26)] for _ in range(len(years))]
    table = [SECTION]
    for p in problems:
        problem_table[years.index(p.year)][int(p.day)] = p

    table.append("<table>")
    table.append("<thead>")
    table.append("<tr>")
    table.append("<th style='text-align:center'>year</th>")
    for day in range(1, 26):
        table.append(
            f"<th style='text-align:center; width: 24px!important'>{day:02}</th>"
        )

    table.append("</tr>")
    table.append("</thead>")
    table.append("<tbody>")

    for i, year in enumerate(years):
        table.append("<tr>")
        table.append(f"<td>{year}</td>")
        for p in problem_table[i][1:]:
            table.append(f"<td>{p.location1 if isinstance(p, Problem) else ''}</td>")
        table.append("</tr>")
    table.append("</tbody>")
    table.append("</table>")
    table.append("")
    return "\n".join(table)


def generateStatistics(problems, keys):
    HEADER = "|Provider|Problem count|"
    DIVIDER = "|-|-|"

    table = [HEADER, DIVIDER]
    for k in keys:
        table.append(f"|[{k}](#{k})|{len(problems[k])}|")

    return "\n".join(table)


def generate():
    problems = collectProblems()

    content = [
        INTRODUCTION,
        generateStatistics(problems, ["advent-of-code", "codechef", "kattis"]),
        generateAdventOfCodeTable(problems["advent-of-code"]),
        problemsAsTable("Codechef", problems["codechef"]),
        problemsAsTable("Kattis", problems["kattis"]),
        "",
        "Icons from [Icons8](https://icons8.com)",
    ]
    print(content)

    with open("README.md", "w") as fh:
        fh.write("\n".join(content))


if __name__ == "__main__":
    generate()
