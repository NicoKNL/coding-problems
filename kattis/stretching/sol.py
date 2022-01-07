import re


def findPossibleLengths(min_length, total_length):
    lengths = []

    for i in range(min_length, total_length + 1):
        if total_length % i == 0:
            lengths.append(i)

    return lengths


def findPossibleWordsOfLength(s, distinct_char_count, length, start_char, end_char):
    possible_words = set()

    for i in range(0, len(s) + 1 - length):
        if s[i] != start_char or s[i + length - 1] != end_char:
            continue

        w = s[i : i + length]

        if len(set(w)) == distinct_char_count:
            possible_words.add(w)

    return list(possible_words)


def findStartingPositions(s, word):
    positions = []
    length = len(word)

    for i in range(0, len(s) + 1 - length):
        w = s[i : i + length]

        if w == word:
            positions.append(i)

    return positions


def extractAtPosition(s, char_count, i):
    return s[:i] + s[i + char_count :]


def s_can_be_reduced_to_word(s, word, cache):
    if s == "":
        return True

    if s in cache:
        return False

    starting_positions = findStartingPositions(s, word)
    found = False

    for p in starting_positions:
        new_s = extractAtPosition(s, len(word), p)
        found = s_can_be_reduced_to_word(new_s, word, cache)

        if found:
            break
        else:
            cache.add(new_s)

    return found
    # print(s)
    # new_s = re.sub(word, "", s)
    # print(new_s)

    # while len(new_s) != len(s):
    #     s = new_s
    #     new_s = re.sub(word, "", s)
    #     print(new_s)

    # print("found:", len(new_s) == 0, len(new_s))
    # return len(new_s) == 0

    # if s == "":
    #     return True

    # new_s = re.sub(word, "", s)
    # # print("{", s, "::", new_s, "}")

    # if len(s) != len(new_s):
    #     return s_can_be_reduced_to_word(new_s, word)

    # return False

    # starting_positions = findStartingPositions(s, word)
    # found = False

    # for p in starting_positions:
    #     found = s_can_be_reduced_to_word(extractAtPosition(s, len(word), p), word)

    #     if found:
    #         break

    # return found


def prefixesCanBuildS(s, prefixes, suffixes, prefix, suffix, cache):
    if prefix == s:
        return True

    # if prefix in cache:
    #     return False

    if len(prefix) == len(s):
        return False

    if not s.startswith(prefix):
        return False

    if (len(prefix) + len(suffix)) == len(s):
        return prefixesCanBuildS(s, prefixes, suffixes, prefix + suffix, "", cache)

    options = len(prefixes) + 2

    if suffix:
        options += 1

    found = False
    for i in range(options):
        if suffix and i == (options - 1):
            found = prefixesCanBuildS(s, prefixes, suffixes, prefix + suffix, "", cache)

        elif i == len(prefixes):
            found = prefixesCanBuildS(
                s, prefixes, suffixes, prefix + prefixes[0] + suffixes[0], suffix, cache
            )

        elif i == len(prefixes) + 1:
            found = prefixesCanBuildS(
                s, prefixes, suffixes, prefix, prefixes[0] + suffixes[0] + suffix, cache
            )
        else:
            found = prefixesCanBuildS(
                s, prefixes, suffixes, prefix + prefixes[i], suffixes[i] + suffix, cache
            )

        if found:
            break

    return found


def getCharCounts(s, multiplier):
    chars = set(s)
    counts = dict()

    for c in chars:
        counts[c] = s.count(c) * multiplier

    return counts


def characterCountMatches(s, w):
    s_counts = getCharCounts(s, 1)

    multiplier = len(s) / len(w)
    w_counts = getCharCounts(w, multiplier)

    for k, v in s_counts.items():
        if w_counts[k] != v:
            return False

    return True


def solve(s=None):
    if not s:
        s = str(input())
    chars = set(s)
    min_length = len(chars)

    if min_length == 1:
        return s[0]

    if min_length == len(s):
        return s

    possible_lengths = findPossibleLengths(min_length, len(s))
    start_char = s[0]
    end_char = s[-1]

    # print(f"input: |{s}|")
    # print(chars, min_length)
    # print(possible_lengths)

    for l in possible_lengths:
        # print("=" * 80)
        possible_words = findPossibleWordsOfLength(
            s, min_length, l, start_char, end_char
        )

        options = []

        for w in sorted(possible_words):
            # print("word:", w)
            if characterCountMatches(s, w):
                options.append(w)
                # prefix_cache = set()  # reset cache

                # if s_can_be_reduced_to_word(s, w, prefix_cache):
                #     return w

                # prefixes, suffixes = generatePrefixesAndSuffixes(w)
                # if prefixesCanBuildS(s, prefixes, suffixes, "", "", prefix_cache):
                #     return w

        if options:
            if any([isPalindrome(w) for w in options]):
                for w in options:
                    if isPalindrome(w):
                        return w
            else:
                return options[0]


def generatePrefixesAndSuffixes(w):
    prefixes = []
    suffixes = []

    for i in range(1, len(w)):
        prefixes.append(w[:i])
        suffixes.append(w[i:])

    return list(reversed(prefixes)), list(reversed(suffixes))


def isPalindrome(w):
    return w == w[::-1]


def test():
    s = "hhehellolloelhellolo"
    w = "hello"
    print(s_can_be_reduced_to_word(s, w))


def test2():
    s = "hhehellolloelhellolo"
    w = "hello"
    for p in findStartingPositions(s, w):
        s = extractAtPosition(s, len(w), p)
        print(s)


def test3():
    s = "wowwwowow"
    w = "wow"
    print("subbed:", re.sub(w, "", s))


def test4():
    print(generatePrefixesAndSuffixes("hallo"))


def test5():
    print("=" * 80)
    s = "wwwwowwwwowwwwowwowwwwwowwwwwwwowwwowwwowwoww"
    w = "wwoww"
    print(solve(s=s))


if __name__ == "__main__":
    print(solve())
    # test()
    # test2()
    # test3()
    # test4()
    # test5()