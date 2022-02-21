#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_SIZE (10005)

int sorter(const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

void extractTreeIntoList_iterative(struct TreeNode *root, int *list, int *listSize) {
  struct TreeNode **stack = malloc(MAX_SIZE * sizeof(*stack));
  int stackTopIdx = -1;

  // in-order
  while (root || stackTopIdx >= 0) {
    if (root) {
      stack[++stackTopIdx] = root;
      // traverse left
      root = root->left;
    } else {
      root = stack[stackTopIdx--];
      list[(*listSize)++] = root->val; // visit
      // traverse right
      root = root->right;
    }
  }
}

void extractTreeIntoList(struct TreeNode *root, int *list, int *listSize) {
  if (!root) return;
  // pre-order
  list[(*listSize)++] = root->val; // visit
  if (root->left)
    extractTreeIntoList(root->left, list, listSize);
  if (root->right)
    extractTreeIntoList(root->right, list, listSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize) {
  int *res = malloc(MAX_SIZE * sizeof(int)); // each tree has 5000 nodes at most

  *returnSize = 0;
  extractTreeIntoList(root1, res, returnSize);
  extractTreeIntoList(root2, res, returnSize);

  qsort(res, *returnSize, sizeof(int), sorter);

  return res;
}

struct TreeNode *newtNode(int value) {
  struct TreeNode *node = malloc(sizeof(*node));
  node->val = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main(int argc, char *argv[]) {
  int *res = malloc(MAX_SIZE * sizeof(int)); // each tree has 5000 nodes at most

  /*
        2           1
      /   \       /   \
     1     4     0     3
  */
  struct TreeNode *root1 = newtNode(1);
  root1->left = newtNode(1);
  root1->right = newtNode(4);
  struct TreeNode *root2 = newtNode(1);
  root2->left = newtNode(0);
  root2->right = newtNode(3);

  int resSize;
  res = getAllElements(root1, root2, &resSize);
  printList(res, resSize);

  return 0;
}
