from typing import List


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0]) if grid else 0
        cnt = m * n
        k %= cnt

        res: List[List[int]] = [[] for _ in range(m)]

        base_idx = (-k + cnt) % cnt  # the index of result value of grid[0][0]
        i, j = base_idx // n, base_idx % n
        for r in range(m):
            for _ in range(n):
                res[r].append(grid[i][j])
                # next cell
                if j == n - 1:
                    j = 0
                    if i == m - 1:
                        i = 0
                    else:
                        i += 1
                else:
                    j += 1

        return res


s = Solution()

res = s.shiftGrid([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1)
print(f"{res = }")
