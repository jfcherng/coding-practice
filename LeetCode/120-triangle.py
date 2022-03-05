from typing import List
import copy


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp: List[List[int]] = copy.deepcopy(triangle)

        for row in range(1, len(triangle)):
            for i in range(rowLen := len(dp[row])):
                # middles
                if 0 < i < rowLen - 1:
                    dp[row][i] += min(dp[row - 1][i], dp[row - 1][i - 1])
                # two ends
                else:
                    dp[row][i] += dp[row - 1][i % (-rowLen)]

        return min(dp[-1])

    # TLE
    def minimumTotal_dfs(self, triangle: List[List[int]]) -> int:
        def dfs(total: int, level: int, idx: int) -> int:
            if level == len(triangle):
                return total

            return min(
                # ...
                dfs(total + triangle[level][idx], level + 1, idx),
                dfs(total + triangle[level][idx], level + 1, idx + 1),
            )

        return dfs(0, 0, 0)


s = Solution()
res = s.minimumTotal([[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]])

print(f"{res = }")
