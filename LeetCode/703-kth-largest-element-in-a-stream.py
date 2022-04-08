from typing import List
import heapq


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k

        self.nums = nums[: min(len(nums), k)]
        heapq.heapify(self.nums)
        for i in range(k, len(nums)):
            heapq.heappushpop(self.nums, nums[i])

    def add(self, val: int) -> int:
        # full
        if len(self.nums) >= self.k:
            heapq.heappushpop(self.nums, val)
        # not full
        else:
            heapq.heappush(self.nums, val)

        return self.nums[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

kthLargest = KthLargest(3, [4, 5, 8, 2])
print(f"{kthLargest.add(3)} (4)")
print(f"{kthLargest.add(5)} (5)")
print(f"{kthLargest.add(10)} (5)")
print(f"{kthLargest.add(9)} (8)")
print(f"{kthLargest.add(4)} (8)")
