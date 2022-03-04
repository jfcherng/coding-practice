from typing import List


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        res: List[str] = []

        def toggleCase(s: str, idx: int) -> str:
            if "a" <= s[idx] <= "z":
                c = s[idx].upper()
            elif "A" <= s[idx] <= "Z":
                c = s[idx].lower()
            else:
                c = s[idx]
            return s[: idx] + c + s[idx + 1 :]

        def isLetter(c: str) -> bool:
            return "a" <= c <= "z" or "A" <= c <= "Z"

        def dfs(s, idx: int) -> None:
            if idx >= len(s):
                res.append(s)
                return

            dfs(s, idx + 1)
            if isLetter(s[idx]):
                dfs(toggleCase(s, idx), idx + 1)

        dfs(s, 0)
        return res


s = Solution()
res = s.letterCasePermutation("a1b2")

print(f"{res = }")
