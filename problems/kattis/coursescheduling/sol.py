from collections import defaultdict


if __name__ == "__main__":
    n = int(input())

    schedule = defaultdict(set)

    for _ in range(n):
        first, last, course = input().split()
        schedule[course].add(first + last)

    for key, value in sorted(schedule.items()):
        print(key, len(value))
