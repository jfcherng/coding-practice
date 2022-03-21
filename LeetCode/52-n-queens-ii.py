from typing import Set


class Solution:
    def totalNQueens(self, n: int) -> int:
        res = 0

        rSet: Set[int] = set()  # used rows
        cSet: Set[int] = set()  # used columns
        tlbrSet: Set[int] = set()  # used top-left to bottom-right diagonals
        trblSet: Set[int] = set()  # used top-right to bottom-left diagonals

        def bt(r: int, c: int) -> None:
            nonlocal res

            if r == n:
                res += 1
                return

            if c == n:
                return

            # can place at (r, c)
            if (
                # ...
                r not in rSet
                and c not in cSet
                and (tlbr := c - r) not in tlbrSet
                and (trbl := c + r) not in trblSet
            ):
                # place at (r, c)
                rSet.add(r)
                cSet.add(c)
                tlbrSet.add(tlbr)
                trblSet.add(trbl)

                bt(r + 1, 0)

                # revert at (r, c)
                rSet.remove(r)
                cSet.remove(c)
                tlbrSet.remove(tlbr)
                trblSet.remove(trbl)

            # try the next cell
            bt(r, c + 1)

        bt(0, 0)
        return res


s = Solution()
res = s.totalNQueens(4)
print(f"{res = }")
