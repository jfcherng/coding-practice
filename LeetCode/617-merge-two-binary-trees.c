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

struct TreeNode *copyTree(struct TreeNode *root) {
  return root ? createTreeNode(root->val, copyTree(root->left), copyTree(root->right)) : NULL;
}

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2) {
  return root1 && root2 ? createTreeNode(root1->val + root2->val,              // ...
                                         mergeTrees(root1->left, root2->left), // ...
                                         mergeTrees(root1->right, root2->right))
                        : copyTree((struct TreeNode *) ((uintptr_t) root1 | (uintptr_t) root2));
}

int main(int argc, char *argv[]) {
  return 0;
}
