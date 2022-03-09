from typing import Generator, List


class Solution:
    def twoSum(
        self, target: int, nums: List[int], l: int, r: int
    ) -> Generator[List[int], None, None]:
        while l < r:
            total = nums[l] + nums[r]

            if total < target:
                l += 1
                continue

            if total > target:
                r -= 1
                continue

            # ans found
            yield [nums[l], nums[r]]
            while True:
                l += 1
                # previously visited
                if l >= r or nums[l] != nums[l - 1]:
                    break

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans: List[List[int]] = []

        nums.sort()
        for idx, val in enumerate(nums):
            # previously visited
            if idx > 0 and nums[idx - 1] == val:
                continue

            for solution in self.twoSum(-val, nums, idx + 1, len(nums) - 1):
                solution.insert(0, val)
                ans.append(solution)

        return ans
