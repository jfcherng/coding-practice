from typing import List


class Solution:
    def findOrder_topological_sort(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        outNodes: List[List[int]] = [[] for _ in range(numCourses)]  # next nodes
        inCnts = [0] * numCourses  # count of incoming edges
        for nxt, pre in prerequisites:
            inCnts[nxt] += 1
            outNodes[pre].append(nxt)

        # basic courses
        done = [i for i, cnt in enumerate(inCnts) if cnt == 0]
        doneIdx = 0

        while doneIdx < len(done):
            node = done[doneIdx]
            doneIdx += 1
            for nxt in outNodes[node]:
                inCnts[nxt] -= 1
                # the course becomes a new "basic" course?
                if inCnts[nxt] == 0:
                    done.append(nxt)

        return done if len(done) == numCourses else []

    findOrder = findOrder_topological_sort


s = Solution()

res = s.findOrder(2, [[1, 0]])
print(f"{res = }")

res = s.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]])
print(f"{res = }")
