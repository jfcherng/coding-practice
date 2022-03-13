#include "_leetcode_common.c"

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

// 2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1)-1 >= 6000
// n = 12, thus 2^n = 2^12 = 4096
#define QUEUE_SIZE (4096)

struct Node *connect(struct Node *root) {
  if (!root)
    return root;

  struct Node **q1 = calloc(QUEUE_SIZE, sizeof(*q1)), **q2 = calloc(QUEUE_SIZE, sizeof(*q2));
  int q1Idx = -1, q2Idx = -1;

  struct Node ***currQ = &q1, ***nextQ = &q2;
  int *currQIdx = &q1Idx, *nextQIdx = &q2Idx;

  // handle root
  (*currQ)[++(*currQIdx)] = root;
  root->next = NULL;

  // level-order traversal
  while (*currQIdx != -1) {
    *nextQIdx = -1;

    for (int i = 0; i <= *currQIdx; ++i) {
      struct Node *node = (*currQ)[i];
      node->next = i < *currQIdx ? (*currQ)[i + 1] : NULL;

      if (node->left)
        (*nextQ)[++(*nextQIdx)] = node->left;
      if (node->right)
        (*nextQ)[++(*nextQIdx)] = node->right;
    }

    // swap currQ and nextQ
    *currQIdx = *nextQIdx;
    struct Node ***tmp = currQ;
    currQ = nextQ;
    nextQ = tmp;
  }

  return root;
}

int main(int argc, char *argv[]) {
  return 0;
}
