from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []

        def print(a: int, b: int) -> str:
            return str(a) if a == b else f"{a}->{b}"

        res = []

        l = r = 0
        while r < len(nums):
            if nums[r] != nums[l] + (r - l):
                res.append(print(nums[l], nums[r - 1]))
                l = r
            r += 1
        res.append(print(nums[l], nums[r - 1]))

        return res


s = Solution()

res = s.summaryRanges([0, 1, 2, 4, 5, 7])
print(f"{res = }")

res = s.summaryRanges([0, 2, 3, 4, 6, 8, 9])
print(f"{res = }")
