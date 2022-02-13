from typing import List
from itertools import chain, combinations


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # one line answer
        # return chain.from_iterable(combinations(nums, r) for r in range(len(nums) + 1))

        res: List[List[int]] = []

        # backtrack
        def bt(nums: List[int], idx: int, subres: List[int]) -> None:
            if idx == len(nums):
                res.append(subres.copy())
                return

            # taken
            subres.append(nums[idx])
            bt(nums, idx + 1, subres)
            subres.pop()

            # not taken
            bt(nums, idx + 1, subres)

        bt(nums, 0, [])
        return res


s = Solution()
res = s.subsets([1, 2, 3])
print(res)
