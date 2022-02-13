from typing import List, Sequence
import math


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        def is_overlapped(a: Sequence[float], b: Sequence[float]):
            return not (a[0] >= b[1] or b[0] >= a[1])

        res = 0
        intervals.sort()

        blocker = [-math.inf, -math.inf]
        for i in range(len(intervals)):
            if is_overlapped(blocker, intervals[i]):
                if blocker[1] > intervals[i][1]:
                    blocker = intervals[i]
                res += 1
            else:
                blocker = intervals[i]

        return res
