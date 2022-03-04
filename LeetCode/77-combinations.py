from typing import List


class Solution:
    # https://leetcode.com/problems/combinations/discuss/26992/
    def combine(self, n: int, k: int) -> List[List[int]]:
        res: List[List[int]] = []

        idx = 0
        nums: List[int] = [1] * k
        while idx >= 0:
            if nums[idx] > n:
                idx -= 1
            elif idx == k - 1:
                res.append(nums.copy())
            else:
                idx += 1
                nums[idx] = nums[idx - 1]
            nums[idx] += 1

        return res

    def combine_slow_bt(self, n: int, k: int) -> List[List[int]]:
        if n < k:
            return []

        def bt(nums: List[int], idx: int, k: int) -> None:
            if idx == k:
                res.append(nums[:k])

            for i in range(idx, len(nums)):
                # ensure the result is sorted to de-duplication
                if idx == 0 or nums[i] >= nums[idx - 1]:
                    nums[idx], nums[i] = nums[i], nums[idx]
                    bt(nums, idx + 1, k)
                    nums[idx], nums[i] = nums[i], nums[idx]

        res: List[List[int]] = []
        bt(list(range(1, n + 1)), 0, k)
        return res


s = Solution()

res = s.combine(4, 2)
print(f"{res = }")
