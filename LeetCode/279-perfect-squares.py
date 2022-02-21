import math


class Solution:
    def numSquares(self, n: int) -> int:
        squares = tuple(i**2 for i in range(1, 1 + int(math.sqrt(n))))

        # BFS (level-order traversal)
        level = 0
        q = {n}
        while q:
            level += 1
            q_next = set()
            for node in q:
                for square in squares:
                    diff = square - node
                    if diff == 0:
                        return level
                    if diff < 0:
                        break
                    q_next.add(diff)
            q = q_next

        # something goes wrong
        return -1


s = Solution()
ans = s.numSquares(12)

print(f"{ans = }")
