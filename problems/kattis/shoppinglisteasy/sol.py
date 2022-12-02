from collections import defaultdict

if __name__ == "__main__":
    n, m = map(int, input().split())

    items = defaultdict(int)

    for _ in range(n):
        words = input().split()
        for w in set(words):
            items[w] += 1

    result = []

    for item, count in items.items():
        if count == n:
            result.append(item)

    result.sort()

    print(len(result))
    for w in result:
        print(w)
