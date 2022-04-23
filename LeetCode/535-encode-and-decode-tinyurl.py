import random
import string
from typing import Dict


class Codec:
    code2url: Dict[str, str] = {}
    url2code: Dict[str, str] = {}
    chars = string.ascii_letters + string.digits

    def encode(self, long_url: str) -> str:
        if long_url in self.url2code:
            return self.url2code[long_url]
        while True:
            if (code := self.getCode()) not in self.code2url:
                break
        self.code2url[code] = long_url
        self.url2code[long_url] = code
        return code

    def decode(self, short_url: str) -> str:
        return self.code2url[short_url]

    @classmethod
    def getCode(cls) -> str:
        code = "".join(random.choice(cls.chars) for _ in range(6))
        return f"http://tinyurl.com/{code}"
