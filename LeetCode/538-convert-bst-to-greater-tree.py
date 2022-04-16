from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def convertBST_recursive(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        carry = 0

        def inorder_reverse(root: Optional[TreeNode]) -> Optional[TreeNode]:
            nonlocal carry

            if not root:
                return None

            inorder_reverse(root.right)
            carry += root.val
            root.val = carry
            inorder_reverse(root.left)

            return root

        return inorder_reverse(root)

    def convertBST_iterative(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        carry = 0
        node = root
        stack: List[TreeNode] = []
        while stack or node:
            if node:
                stack.append(node)
                node = node.right
            else:
                node = stack.pop()
                carry += node.val
                node.val = carry
                node = node.left

        return root

    convertBST = convertBST_iterative
