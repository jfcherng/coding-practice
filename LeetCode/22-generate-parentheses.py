from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(s: str, l: int, r: int) -> List[str]:
            """
            :param      s:    Accumulated string
            :param      l:    Remained numbers of "("s
            :param      r:    Remained numbers of ")"s
            """
            if l > r or l < 0 or r < 0:
                return []

            if l == r == 0:
                return [s]

            return [
                *generate(s + "(", l - 1, r),
                *generate(s + ")", l, r - 1),
            ]

        return generate("", n, n) if n > 0 else []


s = Solution()
ans = s.generateParenthesis(3)

print(ans)
