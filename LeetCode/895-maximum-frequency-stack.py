from collections import defaultdict
from typing import DefaultDict, List, Tuple
import heapq


# time complexity = O(log n) because heap push/pop is O(log n)
# space complexity = O(n) because the heap may store all pushed values
class FreqStack_heap:
    def __init__(self):
        # a max-heap of (freq, pushId, val)
        # which is a min-heap of (-freq, -pushId, val)
        self.heap: List[Tuple[int, int, int]] = []  # min-heap
        self.num2freq: DefaultDict[int, int] = defaultdict(int)
        self.pushId = 0  # nth pushed element

    def push(self, val: int) -> None:
        self.num2freq[val] += 1
        heapq.heappush(self.heap, (-self.num2freq[val], -self.pushId, val))
        self.pushId += 1

    def pop(self) -> int:
        val = heapq.heappop(self.heap)[2]
        self.num2freq[val] -= 1
        return val


# time complexity = O(1)
# space complexity = O(n) because each pushed val is only stored at one place
class FreqStack_stack_of_stacks:
    def __init__(self):
        self.num2freq: DefaultDict[int, int] = defaultdict(int)
        self.freq2nums: DefaultDict[int, List[int]] = defaultdict(list)
        self.maxFreq = 0

    def push(self, val: int) -> None:
        self.num2freq[val] += 1
        self.freq2nums[self.num2freq[val]].append(val)
        self.maxFreq = max(self.maxFreq, self.num2freq[val])

    def pop(self) -> int:
        val = self.freq2nums[self.maxFreq].pop()
        self.num2freq[val] -= 1
        self.maxFreq -= bool(not self.freq2nums[self.maxFreq])
        return val


FreqStack = FreqStack_stack_of_stacks

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()

s = FreqStack()
