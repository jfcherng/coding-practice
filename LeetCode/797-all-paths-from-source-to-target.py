from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs() -> None:
            if (curr := path[-1]) == goal:
                res.append(path.copy())
                return

            for neighbor in graph[curr]:
                path.append(neighbor)
                dfs()
                path.pop()

        # the graph is a DAG, we don't need to track visited
        res: List[List[int]] = []
        path: List[int] = [0]
        goal = len(graph) - 1
        dfs()
        return res


s = Solution()

res = s.allPathsSourceTarget([[1, 2], [3], [3], []])
print(f"{res = }")
