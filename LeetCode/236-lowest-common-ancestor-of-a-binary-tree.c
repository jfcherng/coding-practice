#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// note that `p` and `q` are both guaranteed to be in the tree
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
  if (!root)
    return NULL;

  if (root == p || root == q)
    return root;

  struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
  struct TreeNode *r = lowestCommonAncestor(root->right, p, q);

  return l && r ? root : (struct TreeNode *) ((uintptr_t) l | (uintptr_t) r);
}

int main(int argc, char *argv[]) {
  return 0;
}
