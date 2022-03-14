from collections import deque
from typing import Deque, List, Set, Tuple

PATH = List[Tuple[int, int]]


class Solution:
    # BFS
    def shortestPathBinaryMatrix(self, grid: List[List[int]], show_path: bool = False) -> int:
        n = len(grid)

        endCell = (n - 1, n - 1)
        visited: Set[Tuple[int, int]] = set()

        directions = (
            # fmt: off
            (-1, -1), (-1, 0), (-1, 1),
            ( 0, -1),          ( 0, 1),
            ( 1, -1), ( 1, 0), ( 1, 1),
            # fmt: on
        )

        q: Deque[PATH] = deque()

        if grid[0][0] == 0:
            cell = (0, 0)
            q.append([cell])
            visited.add(cell)

        while q:
            path = q.popleft()
            if (cell := path[-1]) == endCell:
                if show_path:
                    print(f"Found {path = }")
                return len(path)

            for direction in directions:
                nextCell = (cell[0] + direction[0], cell[1] + direction[1])
                if (
                    nextCell not in visited
                    and 0 <= nextCell[0] < n
                    and 0 <= nextCell[1] < n
                    and grid[nextCell[0]][nextCell[1]] == 0
                ):
                    q.append(path.copy() + [nextCell])
                    visited.add(nextCell)

        return -1


s = Solution()

res = s.shortestPathBinaryMatrix([[0, 0, 0], [1, 1, 0], [1, 1, 0]], True)
print(f"{res = }")

res = s.shortestPathBinaryMatrix([[1, 0, 0], [1, 1, 0], [1, 1, 0]], True)
print(f"{res = }")

res = s.shortestPathBinaryMatrix([[0, 0, 1, 0], [1, 0, 1, 0], [1, 1, 0, 1], [0, 0, 0, 0]], True)
print(f"{res = }")
