#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *createTreeNode(int val, struct TreeNode *left, struct TreeNode *right) {
  struct TreeNode *node = malloc(sizeof(*node));
  node->val = val;
  node->left = left;
  node->right = right;
  return node;
}

struct TreeNode *sortedArrayToBST_LR(int *nums, int numsSize, int l, int r) {
  if (l > r)
    return NULL;

  int mid = l + (r - l) / 2;

  return createTreeNode(nums[mid],                                       // ...
                        sortedArrayToBST_LR(nums, numsSize, l, mid - 1), // ...
                        sortedArrayToBST_LR(nums, numsSize, mid + 1, r));
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
  return sortedArrayToBST_LR(nums, numsSize, 0, numsSize - 1);
}

int main(int argc, char *argv[]) {
  return 0;
}
