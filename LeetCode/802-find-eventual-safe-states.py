from typing import Dict, List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        res: List[int] = []
        safe: Dict[int, bool] = {}

        def dfs(node: int) -> bool:
            if node in safe:
                return safe[node]
            safe[node] = False
            for neighbor in graph[node]:
                if not dfs(neighbor):
                    return False
            safe[node] = True
            return True

        for node in range(len(graph)):
            if dfs(node):
                res.append(node)

        return res


s = Solution()

res = s.eventualSafeNodes([[1, 2], [2, 3], [5], [0], [5], [], []])
print(f"{res = } ([2,4,5,6])")

res = s.eventualSafeNodes([[1, 2, 3, 4], [1, 2], [3, 4], [0, 4], []])
print(f"{res = } ([4])")
