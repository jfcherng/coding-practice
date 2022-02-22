from collections import Counter
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        tmp: List[int] = []
        cnt = Counter(nums)

        def bt() -> None:
            if len(tmp) == len(nums):
                res.append(tmp.copy())
                return

            # de-duplication
            for num in cnt:
                if cnt[num] > 0:
                    # add
                    tmp.append(num)
                    cnt[num] -= 1
                    # continue the exploration
                    bt()
                    # revert
                    tmp.pop()
                    cnt[num] += 1

        bt()
        return res


s = Solution()
res = s.permuteUnique([1, 1, 2])

print(f"{res = }")
