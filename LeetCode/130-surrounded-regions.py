from collections import deque
from itertools import chain, product
from typing import Deque, List, Set, Tuple

Cell = Tuple[int, int]


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def enqueue(r: int, c: int) -> None:
            if board[r][c] == "O":
                board[r][c] = "#"
                q.append((r, c))

        m = len(board)
        n = len(board[0]) if m else 0
        directions = ((-1, 0), (0, 1), (1, 0), (0, -1))

        # BFS
        # A region of "O"s is not surrounded if it can reach a "O" on the board boundary.
        # We do it reversely: exploring regions starting from "O"s on the board boundary.
        # We use "#" to represent a cell is visited and not 4-surrounded.

        boundary: Set[Cell] = set(
            (r, c)
            for r, c in chain(
                product(range(m), (0, n - 1)),
                product((0, m - 1), range(n)),
            )
        )

        # put all "O"s on the boundary into queue
        q: Deque[Cell] = deque()
        for r, c in boundary:
            enqueue(r, c)

        while q:
            r, c = q.popleft()
            for dr, dc in directions:  # deltaR, deltaC
                nr, nc = r + dr, c + dc  # nextR, nextC
                if 0 <= nr < m and 0 <= nc < n:
                    enqueue(nr, nc)

        trans = {"X": "X", "#": "O", "O": "X"}
        for r, c in product(range(m), range(n)):
            board[r][c] = trans[board[r][c]]


s = Solution()

board = [
    ["O", "X", "X", "O", "X"],
    ["X", "O", "O", "X", "O"],
    ["X", "O", "X", "O", "X"],
    ["O", "X", "O", "O", "O"],
    ["X", "X", "O", "X", "O"],
]
s.solve(board)
print(f"{board = }")
assert board == [
    ["O", "X", "X", "O", "X"],
    ["X", "X", "X", "X", "O"],
    ["X", "X", "X", "O", "X"],
    ["O", "X", "O", "O", "O"],
    ["X", "X", "O", "X", "O"],
]
