#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *searchBST(struct TreeNode *root, int val) {
  while (root) {
    if (root->val > val) {
      root = root->left;
    } else if (root->val < val) {
      root = root->right;
    } else {
      return root;
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  return 0;
}
