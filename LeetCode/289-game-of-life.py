from itertools import product
from typing import List, Set, Tuple


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0]) if board else 0
        # fmt: off
        directions = (
            (-1, -1), (-1, 0), (-1, 1),
            ( 0, -1),          ( 0, 1),
            ( 1, -1), ( 1, 0), ( 1, 1),
        )
        # fmt: on

        # current live, neighbors = 2~3 live
        # current dead, neighbors = 3 live
        will_live: Set[Tuple[int, int]] = {(1, 2), (1, 3), (0, 3)}  # (current, live_cnt)

        # LSB = current state, MSB = next state
        for r, c in product(range(m), range(n)):
            # count living neighbors
            live_cnt = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and (board[nr][nc] & 1) == 1:
                    live_cnt += 1

            if (board[r][c] & 1, live_cnt) in will_live:
                board[r][c] |= 1 << 1

        for r, c in product(range(m), range(n)):
            board[r][c] >>= 1


s = Solution()

board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
s.gameOfLife(board)
print(f"{board = }")
