from typing import List, Set, Tuple


def renderBoard(n: int, queens: Set[Tuple[int, int]]) -> List[str]:
    board: List[List[str]] = [["." for _ in range(n)] for _ in range(n)]
    for r, c in queens:
        board[r][c] = "Q"
    return ["".join(row) for row in board]


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res: List[List[str]] = []

        queens: Set[Tuple[int, int]] = set()  # position of queens
        rSet: Set[int] = set()  # used rows
        cSet: Set[int] = set()  # used columns
        tlbrSet: Set[int] = set()  # used top-left to bottom-right diagonals
        trblSet: Set[int] = set()  # used top-right to bottom-left diagonals

        def bt(r: int, c: int) -> None:
            if len(queens) == n:
                res.append(renderBoard(n, queens))
                return

            if c == n or r == n:
                return

            # can place at (r, c)
            if (
                r not in rSet
                and c not in cSet
                and (tlbr := c - r) not in tlbrSet
                and (trbl := c + r) not in trblSet
            ):
                # place at (r, c)
                queens.add((r, c))
                rSet.add(r)
                cSet.add(c)
                tlbrSet.add(tlbr)
                trblSet.add(trbl)

                bt(r + 1, 0)

                # revert at (r, c)
                queens.remove((r, c))
                rSet.remove(r)
                cSet.remove(c)
                tlbrSet.remove(tlbr)
                trblSet.remove(trbl)

            # try the next cell
            bt(r, c + 1)

        bt(0, 0)
        return res


s = Solution()
res = s.solveNQueens(4)
print(f"{res = }")
