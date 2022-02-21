#include "_leetcode_common.h"

int sumNumbers(struct TreeNode *root) {
  if (!root || !root->left && !root->right) {
    return root ? root->val : 0;
  }

  int sum = 0;

  if (root->left) {
    root->left->val += root->val * 10;
    sum += sumNumbers(root->left);
  }
  if (root->right) {
    root->right->val += root->val * 10;
    sum += sumNumbers(root->right);
  }

  return sum;
}

int main(int argc, char *argv[]) {
  return 0;
}
