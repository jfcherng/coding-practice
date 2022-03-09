from typing import Deque, List, Tuple
from collections import deque


class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, newColor: int
    ) -> List[List[int]]:
        if (sourceColor := image[sr][sc]) == newColor:
            return image

        m = len(image)
        n = len(image[0]) if m else 0
        q: Deque[Tuple[int, int]] = deque()  # BFS queue
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        q.append((sr, sc))
        while q:
            sr, sc = q.popleft()
            image[sr][sc] = newColor
            for direction in directions:
                r, c = sr + direction[0], sc + direction[1]
                if 0 <= r < m and 0 <= c < n and image[r][c] == sourceColor:
                    q.append((r, c))

        return image


s = Solution()

res = s.floodFill([[1, 1, 1], [1, 1, 0], [1, 0, 1]], 1, 1, 2)
print(f"{res = }")


res = s.floodFill([[0, 0, 0], [0, 1, 1]], 1, 1, 1)
print(f"{res = }")
