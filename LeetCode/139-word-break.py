from typing import List


class Solution:
    def wordBreak(self, s: str, wordList: List[str]) -> bool:
        # dp[i] = whether s[i:] can be cut or not
        sLen = len(s)
        dp: List[bool] = [False] * (sLen + 1)
        dp[sLen] = True  # s[sLen:] = empty string = always matchable

        for i in range(sLen - 1, -1, -1):
            for word in wordList:
                if s[i:].startswith(word) and dp[i + len(word)]:
                    dp[i] = True
                    break

        return dp[0]


s = Solution()

res = s.wordBreak("applepenapple", ["apple", "pen"])
print(f"{res = }")
