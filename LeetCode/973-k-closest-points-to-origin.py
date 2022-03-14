from typing import List
import heapq


def distance2(p: List[int]) -> int:
    return p[0] ** 2 + p[1] ** 2


class Solution:
    def kClosest_quick_select(self, points: List[List[int]], k: int) -> List[List[int]]:
        def partition(points: List[List[int]], l: int, r: int) -> int:
            pivot_idx = l + (r - l) // 2  # use middle as pivot
            pivot_dist = distance2(points[pivot_idx])
            while l <= r:
                if distance2(points[l]) >= pivot_dist:
                    points[l], points[r] = points[r], points[l]
                    r -= 1
                else:
                    l += 1
            return l  # now all distances of points[0..l) < pivot_dist

        def quick_select(points: List[List[int]], k: int) -> List[List[int]]:
            l, r, pivot_idx = 0, len(points) - 1, len(points)
            while pivot_idx != k:
                pivot_idx = partition(points, l, r)
                if pivot_idx > k:
                    r = pivot_idx - 1
                elif pivot_idx < k:
                    l = pivot_idx
            return points[:k]

        return quick_select(points, k)

    def kClosest_heap(self, points: List[List[int]], k: int) -> List[List[int]]:
        # a max heap whose size is `k`
        heap = [(-distance2(points[i]), points[i]) for i in range(k)]
        heapq.heapify(heap)

        for i in range(k, len(points)):
            heapq.heappushpop(heap, (-distance2(points[i]), points[i]))

        return [p for negDis, p in heap]

    kClosest = kClosest_quick_select


s = Solution()

res = s.kClosest([[3, 3], [5, -1], [-2, 4]], 2)
print(f"{res = }")
