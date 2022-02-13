from typing import List, Tuple


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        def fill_border(
            matrix: List[List[int]],
            top_left: Tuple[int, int],
            bottom_right: Tuple[int, int],
            base_value: int,
        ) -> None:
            width = bottom_right[0] - top_left[0] + 1
            print(width, top_left, bottom_right)

            for i in range(width - 1):
                # top row
                matrix[top_left[0]][top_left[1] + i] = (base_value + i)
                # right column
                matrix[top_left[0] + i][bottom_right[1]] = (base_value + i) + (width - 1)
                # bottom row
                matrix[bottom_right[0]][bottom_right[1] - i] = (base_value + i) + (width - 1) * 2
                # left column
                matrix[bottom_right[0] - i][top_left[1]] = (base_value + i) + (width - 1) * 3
            else:
                # center cell
                matrix[top_left[0]][top_left[1]] = base_value

        width = n

        matrix: List[List[int]] = []
        for _ in range(width):
            matrix.append([-1] * width)

        nth_run = 0
        base_value = 1
        while nth_run <= (width-1) // 2:
            fill_border(
                matrix,
                top_left=(nth_run, nth_run),
                bottom_right=(width - nth_run - 1, width - nth_run - 1),
                base_value=base_value,
            )
            base_value += 4 * (width - 2 * nth_run - 1)
            nth_run += 1

        return matrix


s = Solution()
print(s.generateMatrix(3))
