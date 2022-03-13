#include "_leetcode_common.c"

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

struct Node *connect(struct Node *root) {
  if (!root)
    return root;

  struct Node *level = root, dummy = {.next = NULL};

  // up to down
  while (level) {
    struct Node *node = level, *prev = &dummy;

    // left to right
    while (node) {
      if (node->left)
        prev = prev->next = node->left;
      if (node->right)
        prev = prev->next = node->right;
      node = node->next;
    }

    level = dummy.next;
    prev->next = NULL;
  }

  return root;
}

int main(int argc, char *argv[]) {
  return 0;
}
