from typing import Dict


class Solution:
    def wordPattern(self, ptn: str, s: str) -> bool:
        p2w: Dict[str, str] = {}  # ptn -> word
        w2p: Dict[str, str] = {}  # word -> ptn
        words = s.split(" ")

        if len(ptn) != len(words):
            return False

        for idx, word in enumerate(words):
            c = ptn[idx]
            if (word in w2p and w2p[word] != c) or (c in p2w and p2w[c] != word):
                return False
            w2p[word] = c
            p2w[c] = word

        return True


s = Solution()

res = s.wordPattern("abba", "dog cat cat dog")
print(f"{res = }")

res = s.wordPattern("abba", "dog dog dog dog")
print(f"{res = }")

res = s.wordPattern("abba", "dog cat cat fish")
print(f"{res = }")

res = s.wordPattern("abc", "dog")
print(f"{res = }")
