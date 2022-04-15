#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *trimBST(struct TreeNode *root, int low, int high) {
  if (!root)
    return NULL;

  // out-of-bound
  if (root->val < low || root->val > high)
    return trimBST(root->val > high ? root->left : root->right, low, high);

  // in-bound
  root->left = trimBST(root->left, low, high);
  root->right = trimBST(root->right, low, high);
  return root;
}

int main(int argc, char *argv[]) {
  return 0;
}
