class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]

        for word in strs[1:]:
            if len(word) < len(prefix):
                prefix = prefix[: len(word)]

            for i, c in enumerate(word):
                if i >= len(prefix):
                    break

                if prefix[i] != c:
                    prefix = prefix[:i]
                    break

        return prefix
