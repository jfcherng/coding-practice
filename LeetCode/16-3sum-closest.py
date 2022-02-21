from typing import List
import sys


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        diff = sys.maxsize
        for i in range(0, len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                if abs(diff) > abs(thisDiff := target - (nums[i] + nums[l] + nums[r])):
                    diff = thisDiff
                if thisDiff > 0:
                    l += 1
                elif thisDiff < 0:
                    r -= 1
                else:
                    return target

        return target - diff


s = Solution()
res = s.threeSumClosest([-1, 2, 1, -4], 1)

print(f"{res = }")
