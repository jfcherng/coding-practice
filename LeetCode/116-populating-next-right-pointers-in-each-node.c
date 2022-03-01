#include "_leetcode_common.c"

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

struct Node *connect(struct Node *root) {
  if (!root)
    return NULL;

  struct Node *node = root;

  while (node->left) {
    struct Node *p = node;

    for (; p; p = p->next) {
      p->left->next = p->right;
      if (p->next)
        p->right->next = p->next->left;
    }

    node = node->left;
  }

  return root;
}

int main(int argc, char *argv[]) {
  return 0;
}
