from typing import List
import heapq
import sys


class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        res = sys.maxsize

        _max = -sys.maxsize
        for i in range(len(nums)):
            # we want a max heap but python only provides min heap
            nums[i] = -nums[i]
            # make sure all even
            if nums[i] % 2:
                nums[i] *= 2
            _max = max(_max, nums[i])

        heapq.heapify(nums)
        while nums[0] % 2 == 0:
            new = nums[0] // 2
            heapq.heapreplace(nums, new)
            _max = max(_max, new)
            res = min(res, _max - nums[0])

        return min(res, _max - nums[0])


s = Solution()

res = s.minimumDeviation([4, 1, 5, 20, 3])
print(f"{res = }")

res = s.minimumDeviation([3, 5])
print(f"{res = }")
