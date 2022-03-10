from bisect import bisect_left
from typing import List, Tuple


class Solution:
    def findLisPath(self, nums: List[int]) -> Tuple[List[int], int]:
        sub: List[int] = []  # store value
        subIdx: List[int] = []  # store index instead of value for tracing path purpose
        # path[i] is the index of previous number in LIS (i.e., where nums[i] comes from)
        path: List[int] = [-1] * len(nums)

        for idx, num in enumerate(nums):
            if len(sub) == 0 or sub[-1] < num:
                path[idx] = -1 if len(subIdx) == 0 else subIdx[-1]
                sub.append(num)
                subIdx.append(idx)
            else:
                # find the index of the smallest number >= num, replace that number with num
                idx = bisect_left(sub, num)
                path[idx] = -1 if idx == 0 else subIdx[idx - 1]
                sub[idx] = num
                subIdx[idx] = idx

        lis: List[int] = []
        parentIdx = subIdx[-1]
        while parentIdx >= 0:
            lis.append(nums[parentIdx])
            parentIdx = path[parentIdx]
        lis.reverse()

        return lis, len(lis)


s = Solution()

lis, lisLen = s.findLisPath([2, 6, 8, 3, 4, 5, 1])
print(f"{lis = }, {lisLen = }")  # [2, 3, 4, 5]
