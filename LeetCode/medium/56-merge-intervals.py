from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        def is_overlapped(a: List[int], b: List[int]) -> bool:
            return not (a[1] < b[0] or a[0] > b[1])

        merged: List[List[int]] = []
        for interval in intervals:
            if not merged or not is_overlapped(merged[-1], interval):
                merged.append(interval)
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged


intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
s = Solution()
print(f"ans: {s.merge(intervals)}")
