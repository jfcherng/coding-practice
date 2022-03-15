from typing import List, Tuple
from collections import Counter


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def bt(subset: List[int], counter: Tuple[Tuple[int, int], ...], idx: int) -> None:
            if idx == len(counter):
                res.append(subset.copy())
                return

            val, cnt = counter[idx]
            # we can take `val` for [0..cnt] times
            for i in range(cnt + 1):
                subset += [val] * i
                bt(subset, counter, idx + 1)
                if i:
                    del subset[-i:]

        res: List[List[int]] = []
        bt([], tuple(Counter(nums).items()), 0)
        return res


s = Solution()

res = s.subsetsWithDup([2, 1, 2])
print(f"{res = }")
