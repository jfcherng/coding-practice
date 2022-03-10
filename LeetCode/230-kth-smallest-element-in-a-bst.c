#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define NONEXISTENT_VALUE (-1)

int inOrder(struct TreeNode *root, int *k) {
  int ret = NONEXISTENT_VALUE;

  if (!root)
    return ret;

  // left child
  if ((ret = inOrder(root->left, k)) != NONEXISTENT_VALUE) {
    return ret;
  }

  // self (found a smallest number)
  if (--(*k) == 0) {
    return root->val;
  }

  // right child
  return inOrder(root->right, k);
}

int kthSmallest(struct TreeNode *root, int k) {
  return inOrder(root, &k);
}

int main(int argc, char *argv[]) {
  return 0;
}
