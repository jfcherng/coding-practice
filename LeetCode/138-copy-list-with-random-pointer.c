#include "_leetcode_common.c"

struct Node {
  int val;
  struct Node *next;
  struct Node *random;
};

struct Node *createNode(int val, struct Node *next, struct Node *random) {
  struct Node *node = malloc(sizeof(*node));
  node->val = val;
  node->next = next;
  node->random = random;
  return node;
}

struct Node *copyRandomList(struct Node *head) {
  if (!head)
    return NULL;

  struct Node *p = NULL;

  // append a cloned node to the source node
  for (p = head; p; p = p->next->next) {
    p->next = createNode(p->val, p->next, p->random);
  }

  // revise `random` to point to cloned node, which is the next node of its source node
  for (p = head; p; p = p->next->next) {
    if (p->next->random) {
      p->next->random = p->next->random->next;
    }
  }

  // strip cloned nodes out from the interleaving linked list
  struct Node *head_new = head->next, *tmp = NULL;
  for (p = head; p; p = p->next) {
    tmp = p->next;
    p->next = tmp->next;
    if (tmp->next) {
      tmp->next = tmp->next->next;
    }
  }

  return head_new;
}

int main(int argc, char *argv[]) {
  return 0;
}
