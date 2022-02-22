from typing import List, Set


def printBoard(board: List[List[str]]) -> None:
    for i in range(len(board)):
        print("".join(board[i]))
    print("\n")


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def getCandidates(r: int, c: int) -> Set[str]:
            """Gets candidates for the cell."""
            top, left = r - (r % 3), c - (c % 3)
            candidates = set(map(str, range(1, 10)))  # "1" ~ "9"
            for i in range(3):
                for j in range(3):
                    k = 3 * i + j  # 0 ~ 8
                    candidates.discard(board[r][k])  # row
                    candidates.discard(board[k][c])  # col
                    candidates.discard(board[top + i][left + j])  # 3x3 block
            return candidates

        def backtracking(nth: int) -> bool:
            """Returns True for fast stopping if an ans is found."""
            if nth == 81:
                return True

            r, c = nth // 9, nth % 9
            if board[r][c] != ".":
                return backtracking(nth + 1)

            for candidate in getCandidates(r, c):
                board[r][c] = candidate
                if backtracking(nth + 1):
                    return True
                board[r][c] = "."

            return False

        backtracking(0)


board_1 = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"],
]

board_1_ans = [
    ["5", "3", "4", "6", "7", "8", "9", "1", "2"],
    ["6", "7", "2", "1", "9", "5", "3", "4", "8"],
    ["1", "9", "8", "3", "4", "2", "5", "6", "7"],
    ["8", "5", "9", "7", "6", "1", "4", "2", "3"],
    ["4", "2", "6", "8", "5", "3", "7", "9", "1"],
    ["7", "1", "3", "9", "2", "4", "8", "5", "6"],
    ["9", "6", "1", "5", "3", "7", "2", "8", "4"],
    ["2", "8", "7", "4", "1", "9", "6", "3", "5"],
    ["3", "4", "5", "2", "8", "6", "1", "7", "9"],
]

s = Solution()

print("---------- board_1 ----------")
printBoard(board_1)
print("---------- board_1 (solved) ----------")
s.solveSudoku(board_1)
printBoard(board_1)

assert board_1 == board_1_ans
print("board_1: GOOD")
