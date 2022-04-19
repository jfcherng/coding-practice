#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recoverTree(struct TreeNode *root) {
  // in-order traversal
  struct TreeNode *q[1001] = {0}, *prev = NULL, *wrong1 = NULL, *wrong2 = NULL;
  int q_idx = -1;

  while (q_idx != -1 || root) {
    if (root) {
      q[++q_idx] = root; // push
      root = root->left;
      continue;
    }

    struct TreeNode *node = q[q_idx--]; // pop
    // visit
    if (prev && prev->val > node->val) {
      // find a greater node
      if (!wrong1)
        wrong1 = prev;
      // find a smaller node
      wrong2 = node;
    }

    prev = node;
    root = node->right;
  }

  // swap node value
  wrong1->val ^= wrong2->val;
  wrong2->val ^= wrong1->val;
  wrong1->val ^= wrong2->val;
}

int main(int argc, char *argv[]) {
  return 0;
}
