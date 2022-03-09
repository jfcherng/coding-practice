from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        res: List[int] = []
        # BFS level-order traversal
        q: List[TreeNode] = []
        q.append(root)

        while q:
            res.append(q[-1].val)

            q_next: List[TreeNode] = []
            for node in q:
                if node.left:
                    q_next.append(node.left)
                if node.right:
                    q_next.append(node.right)
            q = q_next

        return res
