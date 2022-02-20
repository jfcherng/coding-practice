from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res: List[List[int]] = []

        def dfs(idx: int, curr: List[int], total: int) -> None:
            if total == target:
                res.append(curr.copy())
                return
            if idx < 0 or total > target:
                return
            # current index taken
            curr.append(candidates[idx])
            dfs(idx, curr, total + candidates[idx])
            curr.pop()
            # current index not taken
            dfs(idx - 1, curr, total)

        dfs(len(candidates) - 1, [], 0)
        return res


s = Solution()
res = s.combinationSum([2, 3, 6, 7], 7)

print(f"{res = }")
