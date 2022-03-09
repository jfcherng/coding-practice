from typing import List


class Solution:
    def intervalIntersection(
        self, l1: List[List[int]], l2: List[List[int]]
    ) -> List[List[int]]:
        res: List[List[int]] = []

        def get_overlapped(interval1: List[int], interval2: List[int]) -> List[int]:
            if interval1[1] < interval2[0] or interval2[1] < interval1[0]:
                return []
            return [max(interval1[0], interval2[0]), min(interval1[1], interval2[1])]

        i1 = i2 = 0
        while i1 < len(l1) and i2 < len(l2):
            if r := get_overlapped(l1[i1], l2[i2]):
                res.append(r)
            # the one ends first is useless now
            if l1[i1][1] < l2[i2][1]:
                i1 += 1
            else:
                i2 += 1

        return res


firstList = [[3, 5], [9, 20]]
secondList = [[4, 5], [7, 10], [11, 12], [14, 15], [16, 20]]

s = Solution()
print(s.intervalIntersection(firstList, secondList))
