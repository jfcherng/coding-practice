#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode *root, int *curr_depth, int *max_depth) {
  if (!root) {
    *max_depth = MAX(*max_depth, *curr_depth);
    return;
  }

  ++*curr_depth;

  inorder(root->left, curr_depth, max_depth);
  inorder(root->right, curr_depth, max_depth);

  --*curr_depth;
}

int maxDepth(struct TreeNode *root) {
  int res = 0;
  int curr_depth = 0;

  inorder(root, &curr_depth, &res);

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
