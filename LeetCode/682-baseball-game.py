from typing import List


class Solution:
    def calPoints(self, ops: List[str]) -> int:
        scores: List[int] = []

        for op in ops:
            if op == "+":
                scores.append(scores[-1] + scores[-2])
            elif op == "C":
                scores.pop()
            elif op == "D":
                scores.append(scores[-1] * 2)
            else:
                scores.append(int(op))

        return sum(scores)
