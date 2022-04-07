from typing import List
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # we want max-heap of `stones` but can only do it in min-heap of `-stones` in Python
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            big_stone = heapq.heappop(stones)
            small_stone = stones[0]  # top

            if big_stone == small_stone:
                heapq.heappop(stones)  # remove `small_stone`
            else:
                heapq.heapreplace(stones, big_stone - small_stone)

        return -stones[0] if len(stones) else 0


s = Solution()

res = s.lastStoneWeight([2, 7, 4, 1, 8, 1])
print(f"{res = } (1)")
