from typing import List, Set, Tuple


class Solution:
    def dijkstra(self, heights: List[List[int]]) -> int:
        ...  # @todo

    def binary_search_dfs(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0]) if heights else 0
        directions = ((-1, 0), (0, 1), (1, 0), (0, -1))

        # DFS
        def is_effort_plausible(r: int, c: int, prev_height: int, effort_upper: int) -> bool:
            if (
                (r, c) in visited
                or r < 0
                or r >= m
                or c < 0
                or c >= n
                or abs(heights[r][c] - prev_height) > effort_upper
            ):
                return False
            if r == m - 1 and c == n - 1:
                return True
            visited.add((r, c))
            return any(
                # all 4 directions
                is_effort_plausible(r + dr, c + dc, heights[r][c], effort_upper)
                for dr, dc in directions
            )

        # binary search
        l, r = (
            0,  # lowerbound of effort
            max(max(row) for row in heights),  # upperbound of effort
        )
        while l <= r:
            visited: Set[Tuple[int, int]] = set()
            mid = l + (r - l) // 2
            if is_effort_plausible(0, 0, heights[0][0], mid):
                r = mid - 1
            else:
                l = mid + 1

        return l

    minimumEffortPath = binary_search_dfs


s = Solution()

res = s.minimumEffortPath([[1, 2, 3], [3, 8, 4], [5, 3, 5]])
print(f"{res = } (1)")
