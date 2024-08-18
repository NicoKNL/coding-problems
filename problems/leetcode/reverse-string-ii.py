class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        chunks = []
        i = 0
        while i < len(s):
            chunk = s[i:i + 2 * k]
            chunk = chunk[:k][::-1] + chunk[k:]
            chunks.append(chunk)
            i += 2 * k

    return "".join(chunks)
