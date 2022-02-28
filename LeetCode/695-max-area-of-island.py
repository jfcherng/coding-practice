from typing import List
from collections import deque


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0]) if m else 0
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        def calculate_island_area(r: int, c: int) -> int:
            area = 0
            q = deque()
            q.append((r, c))
            while q:
                r, c = q.popleft()
                if grid[r][c] != 1:
                    continue
                grid[r][c] *= -1  # visited
                area += 1
                for direction in directions:
                    r_tmp, c_tmp = r + direction[0], c + direction[1]
                    if 0 <= r_tmp < m and 0 <= c_tmp < n and grid[r_tmp][c_tmp] == 1:
                        q.append((r_tmp, c_tmp))
            return area

        res = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    res = max(res, calculate_island_area(r, c))
        # restore data (if necessary)
        for r in range(m):
            for c in range(n):
                grid[r][c] *= -1
        return res


s = Solution()

res = s.maxAreaOfIsland(
    [
        [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    ]
)
print(f"{res = } (6)")

res = s.maxAreaOfIsland(
    [
        [1, 1, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 1, 1],
    ]
)
print(f"{res = } (4)")

res = s.maxAreaOfIsland(
    [
        [0, 0, 0, 0, 0, 0, 0, 0],
    ]
)
print(f"{res = } (0)")
