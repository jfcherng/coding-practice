#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isIdenticalTree(struct TreeNode *root1, struct TreeNode *root2) {
  // at least one is NULL
  if (!(root1 && root2))
    return root1 == root2;
  // both non-NULL
  return root1->val == root2->val &&                  // ...
         isIdenticalTree(root1->left, root2->left) && // ...
         isIdenticalTree(root1->right, root2->right);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot) {
  if (isIdenticalTree(root, subRoot))
    return true;

  if (!root || !subRoot)
    return false;

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(int argc, char *argv[]) {
  return 0;
}
