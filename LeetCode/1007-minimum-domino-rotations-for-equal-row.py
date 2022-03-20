from typing import List


class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        # the target number must be in all of {top, bottom} pairs
        candidates = {tops[0], bottoms[0]}
        for i in range(1, len(tops)):
            candidates &= {tops[i], bottoms[i]}
            if not candidates:
                return -1

        target = candidates.pop()
        step_tops = step_bottoms = 0
        for i in range(len(tops)):
            step_tops += tops[i] != target
            step_bottoms += bottoms[i] != target

        return min(step_tops, step_bottoms)


s = Solution()

res = s.minDominoRotations([2, 1, 2, 4, 2, 2], [5, 2, 6, 2, 3, 2])
print(f"{res = }")
