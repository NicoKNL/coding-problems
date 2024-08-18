from random import choice 

_HASH_CHARS = "abcdefghijklmnopqrstuvwxyz1234567890-_"
_HASH_LENGTH = 8
_BASE_URL = "https://tinyurl.com/"

def _generateHash() -> str:
    return "".join(choice(_HASH_CHARS) for _ in range(_HASH_LENGTH))

class Codec:
    def __init__(self):
        self.short2long = {}
        self.long2short = {}

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        if longUrl in self.long2short:
            return self.long2short[longUrl]

        shortUrl = _BASE_URL + _generateHash()

        self.short2long[shortUrl] = longUrl
        self.long2short[longUrl] = shortUrl

        return self.long2short[longUrl]
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.short2long[shortUrl]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
