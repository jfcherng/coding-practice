from typing import List
import itertools
import sys


class Solution:
    def splitArray_binary_search(self, nums: List[int], m: int) -> int:
        def canSplit(targetSum: int, m: int) -> bool:
            """Can `nums` be split into `m` contiguous subarrays whose sums are <= `targetSum` ?"""
            accumulation, parts = 0, 1
            for num in nums:
                accumulation += num
                if accumulation > targetSum:
                    accumulation = num
                    parts += 1
            return parts <= m

        # `l` = min possible largest split array sum
        # `r` = max possible largest split array sum
        l, r = max(nums), sum(nums)

        res = sys.maxsize
        while l <= r:
            mid = l + (r - l) // 2
            if canSplit(mid, m):
                res = mid
                r = mid - 1
            else:
                l = mid + 1

        return res

    def splitArray_dp(self, nums: List[int], m: int) -> int:
        n = len(nums)

        # prefix sum, ps[i] = nums[0] + ... + num[i-1]
        ps = [0] + list(itertools.accumulate(nums))

        # dp[i][j] = min largest sum for nums[i..n) where m = j
        dp = [[-1] * (m + 1) for _ in range(n)]
        # base cases (m = 1)
        for i in range(n):
            dp[i][1] = ps[n] - ps[i]

        # fill table
        for j in range(2, m + 1):
            for i in range(n):
                min_res = ps[n]  # upper bound
                # for m = j, we split nums[i..n) into nums[i..k] and nums[k+1..n)
                # where nums[i..k] is the `j`th split and min largest sum of nums[k+1..n) is dp[k+1][j-1]
                for k in range(i, n - (j - 1)):
                    min_res = min(
                        min_res,
                        max(
                            split_sum := ps[k + 1] - ps[i],  # sum of the `j`th split
                            dp[k + 1][j - 1],  # the largest sum of other `j-1` splits
                        ),
                    )
                    if split_sum >= min_res:
                        break
                dp[i][j] = min_res

        return dp[0][m]

    splitArray = splitArray_binary_search


s = Solution()

res = s.splitArray([7, 2, 5, 10, 8], 2)
print(f"{res = } (18)")

res = s.splitArray([1, 4, 4], 3)
print(f"{res = } (4)")
