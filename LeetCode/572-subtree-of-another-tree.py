from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.hash = ""


def hash(x: str) -> str:
    from hashlib import sha256

    S = sha256()
    S.update(x.encode("utf-8"))
    return S.hexdigest()


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def add_merkle_hash(node: Optional[TreeNode]) -> str:
            """See https://en.wikipedia.org/wiki/Merkle_tree"""
            if not node:
                return "$"
            # this hash represents the whole subtree whose root is `node`
            node.hash = hash(add_merkle_hash(node.left) + str(node.val) + add_merkle_hash(node.right))
            return node.hash

        assert root and subRoot
        add_merkle_hash(root)
        add_merkle_hash(subRoot)

        def dfs(node: Optional[TreeNode]) -> bool:
            return (node.hash == subRoot.hash or dfs(node.left) or dfs(node.right)) if node else False

        return dfs(root)
