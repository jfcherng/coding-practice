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

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
  // the preorder[0] is the tree root
  if (preorderSize == 0)
    return NULL;

  // find the index of the tree root in the inorder array
  // and then the left part of the inorder array is the left child
  // and the right part of the inorder array is the right child
  int i = 0;
  for (; inorder[i] != preorder[0]; ++i)
    ;

  // the left child size and the right child size
  int lSize = i, rSize = inorderSize - lSize - 1;
  return createTreeNode(preorder[0], // ...
                        buildTree(preorder + 1 /*   */, lSize, inorder /*       */, lSize),
                        buildTree(preorder + 1 + lSize, rSize, inorder + lSize + 1, rSize));
}

int main(int argc, char *argv[]) {
  return 0;
}
