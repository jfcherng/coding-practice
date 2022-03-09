#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
  struct TreeNode **pp = &root;

  while (*pp) {
    if ((*pp)->val > key) {
      pp = &((*pp)->left);
      continue;
    }
    if ((*pp)->val < key) {
      pp = &((*pp)->right);
      continue;
    }
    // now, *pp is the node to be deleted

    // deleted node has no child
    if (!(*pp)->left && !(*pp)->right) {
      free(*pp);
      *pp = NULL;
    }
    // deleted node has only left child
    else if (!(*pp)->right) {
      struct TreeNode *tmp = *pp;
      *pp = (*pp)->left;
      free(tmp);
    }
    // deleted node has only right child
    else if (!(*pp)->left) {
      struct TreeNode *tmp = *pp;
      *pp = (*pp)->right;
      free(tmp);
    }
    // deleted node has both children
    else {
      // get the next incresing value with respect to the deleted node
      // i.e., go right once and then go left until there is no left
      struct TreeNode **next = &((*pp)->right);
      while ((*next)->left)
        next = &((*next)->left);
      // use *next to replace the deleted node (*pp)
      struct TreeNode *tmp = *next;
      *next = (*next)->right;
      tmp->left = (*pp)->left;
      tmp->right = (*pp)->right;
      free(*pp);
      *pp = tmp;
    }

    // there is only one target node to be deleted in the tree
    break;
  }

  return root;
}

int main(int argc, char *argv[]) {
  return 0;
}
