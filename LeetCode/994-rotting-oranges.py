from typing import List, Set, Tuple

CELL_EMPTY = 0
CELL_GOOD = 1
CELL_BAD = 2

RC = Tuple[int, int]


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0]) if grid else 0
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        good_cnt = 0
        bad_rcs: Set[RC] = set()
        for r in range(m):
            for c in range(n):
                if grid[r][c] == CELL_GOOD:
                    good_cnt += 1
                if grid[r][c] == CELL_BAD:
                    bad_rcs.add((r, c))

        res = 0
        while True:
            bad_rcs_next: Set[RC] = set()

            for bad_rc in bad_rcs:
                for direction in directions:
                    r, c = bad_rc[0] + direction[0], bad_rc[1] + direction[1]
                    if 0 <= r < m and 0 <= c < n and grid[r][c] == CELL_GOOD:
                        grid[r][c] = CELL_BAD
                        good_cnt -= 1
                        bad_rcs_next.add((r, c))

            if not bad_rcs_next:
                break

            bad_rcs = bad_rcs_next
            res += 1

        return -1 if good_cnt > 0 else res


s = Solution()

res = s.orangesRotting(
    [
        [2, 1, 1],
        [0, 1, 1],
        [1, 0, 1],
    ]
)
print(f"{res = } (-1)")

res = s.orangesRotting([[0, 2]])
print(f"{res = } (0)")
