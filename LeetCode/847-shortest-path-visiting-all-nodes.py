is_debug = 1


from typing import Dict, List, Set, Tuple
import sys

StateType = Tuple[int, int]


def debug_print(*args, **kwargs) -> None:
    try:
        if is_debug:
            print(*args, **kwargs)
    except NameError:
        pass  # "is_debug" is undefiend


class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        if (n := len(graph)) == 1:
            return 0

        ending_mask = (1 << n) - 1
        q: List[StateType] = [(node, 1 << node) for node in range(n)]  # queue
        seen: Set[StateType] = set(q)
        steps = 0
        while q:
            q_next: List[StateType] = []
            for node, mask in q:
                for neighbor in graph[node]:
                    next_mask = mask | (1 << neighbor)
                    if next_mask == ending_mask:
                        return steps + 1
                    if (next_state := (neighbor, next_mask)) not in seen:
                        seen.add(next_state)
                        q_next.append(next_state)
            steps += 1
            q = q_next

        return -1  # can't visit all nodes

    def shortestPathLength_dfs(self, graph: List[List[int]]) -> int:
        def dfs(node: int, mask: int) -> int:
            debug_print(f"=> visit node {node} with mask({format(mask, '04b')})")
            if (state := (node, mask)) in cache:
                return cache[state]

            if (mask | (1 << node)) == ending_mask:
                debug_print("!! found")
                return 0

            cache[state] = sys.maxsize
            for neighbor in graph[node]:
                if mask & (1 << neighbor) == 0:  # neighbor has not visited yet
                    cache[state] = min(
                        cache[state],
                        1 + dfs(neighbor, mask | (1 << node)),  # node visited before
                        1 + dfs(neighbor, mask),  # node not visited before
                    )

            return cache[state]

        n = len(graph)
        ending_mask = (1 << n) - 1
        cache: Dict[StateType, int] = {}

        least = sys.maxsize
        for node in range(n):
            debug_print(f"★ started at node {node}")
            least = min(least, dfs(node, 0))

        return least


s = Solution()

# res = s.shortestPathLength([[]])
# print(f"{res = } (0)")

res = s.shortestPathLength([[1, 2, 3], [0], [0], [0]])
print(f"{res = } (4)")

# res = s.shortestPathLength([[1],[0,2,4],[1,3,4],[2],[1,2]])
# print(f"{res = } (4)")
