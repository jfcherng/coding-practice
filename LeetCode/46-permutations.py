from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []

        def bt(idx: int) -> None:
            """Determinates the num at idx."""
            if idx == len(nums):
                res.append(nums.copy())
                return

            for i in range(idx, len(nums)):
                nums[i], nums[idx] = nums[idx], nums[i]
                bt(idx + 1)
                nums[i], nums[idx] = nums[idx], nums[i]

        bt(0)

        return res


s = Solution()
res = s.permute([1, 2, 3])

print(f"{res = }")
