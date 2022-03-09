from functools import cmp_to_key
from typing import List


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        def is_covered(a: List[int], b: List[int]) -> bool:
            """Determines whether a covers b."""
            return a[0] <= b[0] and b[1] <= a[1]

        if not intervals:
            return 0

        res = len(intervals)
        intervals.sort(
            key=cmp_to_key(lambda a, b: a[0] - b[0] if a[0] != b[0] else b[1] - a[1])
        )

        prev = intervals[0]
        for i in range(1, res):
            if is_covered(prev, intervals[i]):
                res -= 1
            else:
                prev = intervals[i]

        return res


s = Solution()
res = s.removeCoveredIntervals([[1, 5], [1, 6], [5, 7]])
print(f"{res = }")
