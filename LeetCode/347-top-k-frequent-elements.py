from collections import Counter
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res: List[int] = []
        counter = Counter(nums)

        cnt2nums: List[List[int]] = [[] for _ in range(len(nums) + 1)]
        for num, cnt in counter.items():
            cnt2nums[cnt].append(num)

        for i in range(len(cnt2nums) - 1, -1, -1):
            for num in cnt2nums[i]:
                res.append(num)
                if len(res) == k:
                    return res

        return res


s = Solution()

res = s.topKFrequent([1, 1, 1, 2, 2, 3], 2)
print(f"{res = }")

res = s.topKFrequent([3, 0, 1, 0], 1)
print(f"{res = }")
