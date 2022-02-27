from collections import deque
from typing import Deque, Optional, Tuple


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # level-order traversal

        if not root:
            return 0

        w_max = 0
        q: Deque[Tuple[TreeNode, int]] = deque()
        q.append((root, 1))  # 1-indexed complete binary tree node index

        while q:
            w_max = max(w_max, q[-1][1] - q[0][1] + 1)

            for _ in range(len(q)):
                node, idx = q.popleft()
                if node.left:
                    q.append((node.left, 2 * idx))
                if node.right:
                    q.append((node.right, 2 * idx + 1))

        return w_max


s = Solution()

tree = TreeNode(
    val=1,
    left=TreeNode(
        val=3,
        left=TreeNode(val=5),
        right=TreeNode(val=3),
    ),
    right=TreeNode(
        val=2,
        right=TreeNode(val=9),
    ),
)
res = s.widthOfBinaryTree(tree)

print(f"{res = }")
