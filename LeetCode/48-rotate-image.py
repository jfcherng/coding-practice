from typing import List, Tuple


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        def rotateBorder(
            matrix: List[List[int]],
            top_left: Tuple[int, int],
            bottom_right: Tuple[int, int],
        ) -> None:
            width = bottom_right[0] - top_left[0] + 1
            top_row = matrix[top_left[0]][:]  # backup the top row

            for i in range(width - 1):
                # left column to top row
                matrix[top_left[0]][top_left[1] + i] = matrix[bottom_right[0] - i][top_left[1]]
                # bottom row to left column
                matrix[bottom_right[0] - i][top_left[1]] = matrix[bottom_right[0]][bottom_right[1] - i]
                # right column to bottom row
                matrix[bottom_right[0]][bottom_right[1] - i] = matrix[top_left[0] + i][bottom_right[1]]
                # top row to right column
                matrix[top_left[0] + i][bottom_right[1]] = top_row[top_left[1] + i]

        width = len(matrix)
        nth = 0
        while nth <= width // 2:
            rotateBorder(matrix, (nth, nth), (width - nth - 1, width - nth - 1))
            nth += 1
