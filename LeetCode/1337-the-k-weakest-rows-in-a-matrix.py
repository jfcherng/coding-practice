from typing import List, Tuple
import heapq


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        def fast_sum(row: List[int]) -> int:
            l, r = 0, len(row) - 1
            while l <= r:
                mid = l + (r - l) // 2
                if row[mid] == 0:
                    r = mid - 1
                else:
                    l = mid + 1
            return l

        res: List[int] = []

        heap: List[Tuple[int, int]] = []  # max-heap of size `k`
        for i in range(k):
            heapq.heappush(heap, (-fast_sum(mat[i]), -i))
        for i in range(k, len(mat)):
            heapq.heappushpop(heap, (-fast_sum(mat[i]), -i))

        for i in range(k):
            res.append(-heapq.heappop(heap)[1])
        res.reverse()

        return res


s = Solution()

res = s.kWeakestRows(
    [
        [1, 1, 0, 0, 0],
        [1, 1, 1, 1, 0],
        [1, 0, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [1, 1, 1, 1, 1],
    ],
    3,
)
print(f"{res = }")
