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

// find minimal height `h` such that `1+2+3+...+h = h*(h+1)/2 >= 100000`
// and we have `h` = 447
#define MAX_BST_HEIGHT (447)

typedef struct {
  struct TreeNode *stack[MAX_BST_HEIGHT];
  int stackTopIdx;
} BSTIterator;

void _bSTIteratorPushAlongLeft(BSTIterator *obj, struct TreeNode *node) {
  // push left till end
  for (; node; node = node->left)
    obj->stack[++(obj->stackTopIdx)] = node;
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
  BSTIterator *obj = malloc(sizeof(*obj));
  // for (int i = 0; i < MAX_BST_HEIGHT; obj->stack[i++] = NULL);
  obj->stackTopIdx = -1;
  _bSTIteratorPushAlongLeft(obj, root);
  return obj;
}

// assume always has next
int bSTIteratorNext(BSTIterator *obj) {
  // pop and visit
  struct TreeNode *node = obj->stack[(obj->stackTopIdx)--];

  _bSTIteratorPushAlongLeft(obj, node->right);
  return node->val;
}

bool bSTIteratorHasNext(BSTIterator *obj) {
  return obj->stackTopIdx != -1;
}

void bSTIteratorFree(BSTIterator *obj) {
  free(obj);
  obj = NULL;
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/

int main(int argc, char *argv[]) {
  return 0;
}
