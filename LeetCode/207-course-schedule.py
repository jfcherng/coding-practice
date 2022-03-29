from typing import List


class Solution:
    def canFinish_topological_sort(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
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

        return len(done) == numCourses

    canFinish = canFinish_topological_sort


s = Solution()

res = s.canFinish(2, [[1, 0]])
print(f"{res = }")
