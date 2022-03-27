from collections import defaultdict
from typing import DefaultDict, List, Tuple
import math

Slope = Tuple[int, int]


def get_slope(dx: int, dy: int) -> Slope:
    # same point (won't happen)
    if dx == dy == 0:
        ...
    # vertical line
    elif dx == 0:
        dy = 1
    # horizontal line
    elif dy == 0:
        dx = 1
    else:
        # to make sure `dx` always non-negative
        # we let `gcd` have the same sign with `dx`
        gcd = int(math.copysign(math.gcd(dx, dy), dx))
        dx, dy = dx // gcd, dy // gcd
    return dx, dy  # `dx` is non-negative


class Solution:
    def maxPoints(self, pts: List[List[int]]) -> int:
        if (ptLen := len(pts)) <= 2:
            return ptLen

        res = 0

        for i, pt in enumerate(pts):
            counter: DefaultDict[Slope, int] = defaultdict(int)
            for j in range(i + 1, ptLen):
                counter[get_slope(pts[j][0] - pt[0], pts[j][1] - pt[1])] += 1
            if counter:
                res = max(res, 1 + max(counter.values()))  # +1 is for `pt` itself

        return res


s = Solution()

res = s.maxPoints([[1, 1], [2, 2], [3, 3]])
print(f"{res = } (3)")

res = s.maxPoints([[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]])
print(f"{res = } (4)")
