from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []

        res: List[List[int]] = []
        path: List[int] = []  # current path

        def dfs(node: Optional[TreeNode], carry: int) -> None:
            if not node:
                return

            path.append(node.val)
            carry += node.val

            if carry == targetSum and not (node.left or node.right):
                res.append(path.copy())

            if node.left:
                dfs(node.left, carry)
            if node.right:
                dfs(node.right, carry)

            path.pop()

        dfs(root, 0)
        return res
