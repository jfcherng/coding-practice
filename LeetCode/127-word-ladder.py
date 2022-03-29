from typing import List
import collections


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def get_pattern(s: str, idx: int) -> str:
            return s[:idx] + "?" + s[idx + 1 :]

        # build neighborship
        neighbors: collections.defaultdict[str, List[str]] = collections.defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                neighbors[get_pattern(word, i)].append(word)

        # BFS
        res = 1
        visited = set((beginWord,))
        q = collections.deque((beginWord,))
        while q:
            for _ in range(len(q)):
                if (word := q.popleft()) == endWord:
                    return res
                for i in range(len(word)):
                    for n in neighbors[get_pattern(word, i)]:
                        if n not in visited:
                            visited.add(n)
                            q.append(n)
            res += 1

        return 0
