from typing import List


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        halfLength = len(costs) >> 1
        costs.sort(key=lambda cost: cost[0] - cost[1])  # affinity to city `a`
        return sum(cost[i // halfLength] for i, cost in enumerate(costs))


s = Solution()

res = s.twoCitySchedCost([[10, 20], [30, 200], [400, 50], [30, 20]])
print(f"{res = }")
