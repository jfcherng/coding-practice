from typing import List

buttons = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
}


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res: List[str] = []
        stack: List[str] = []
        l = len(digits)

        def bt(i: int):
            if i >= l:
                if stack:
                    res.append("".join(stack))
                return

            for c in buttons[digits[i]]:
                stack.append(c)
                bt(i + 1)
                stack.pop()

        bt(0)
        return res


s = Solution()
res = s.letterCombinations("23")
print(f"{res = }")
