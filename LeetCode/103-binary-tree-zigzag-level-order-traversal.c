#include "_leetcode_common.c"

#define BIG_SIZE (2001)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
  int **res = calloc(BIG_SIZE, sizeof(*res));
  *returnColumnSizes = calloc(BIG_SIZE, sizeof(**returnColumnSizes));
  *returnSize = 0;

  if (!root)
    return res;

  // root is at 0th level
  int level = 0;

  // current queue and next queue
  struct TreeNode *q[BIG_SIZE] = {}, *qNext[BIG_SIZE] = {};
  int qIdx = -1, qNextIdx = -1;

  // pointers to current queue and next queue
  struct TreeNode *(*pq)[] = &q, *(*pqNext)[] = &qNext;
  int *pqIdx = &qIdx, *pqNextIdx = &qNextIdx;

  // append root into current queue
  (*pq)[++*pqIdx] = root;

  // BFS
  while ((*pqIdx) >= 0) {
    (*returnColumnSizes)[level] = *pqIdx + 1;
    res[level] = malloc((*returnColumnSizes)[level] * sizeof(**res));

    for (int i = 0; i <= *pqIdx; ++i) {
      struct TreeNode *node = (*pq)[i]; // shorthand

      // odd 0-index level = RTL, even 0-index level = LTR
      res[level][(level & 1) ? (*pqIdx - i) : i] = node->val;

      // append children into next queue
      if (node->left)
        (*pqNext)[++*pqNextIdx] = node->left;
      if (node->right)
        (*pqNext)[++*pqNextIdx] = node->right;
    }

    ++level;

    // swap current quque and next queue
    *pqIdx = *pqNextIdx;
    struct TreeNode *(*tmp)[] = pq;
    pq = pqNext;
    pqNext = tmp;
    // empty next queue
    *pqNextIdx = -1;
  }

  *returnSize = level;

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
