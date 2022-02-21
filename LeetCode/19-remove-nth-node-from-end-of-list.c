#include "_leetcode_common.c"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode **first = &head, **second = &head;

  while (n-- > 0 && *first) {
    first = &((*first)->next);
  }

  while (*first) {
    first = &((*first)->next);
    second = &((*second)->next);
  }

  // remove node
  struct ListNode *target = *second;
  *second = (*second)->next;
  free(target);

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *head;

  int vals_1[] = {1, 2, 3, 4, 5};
  head = createListNodesFromList(vals_1, sizeof(vals_1) / sizeof(int));

  printf("input(%d): ", 2);
  printListNodes(head);
  printf("output: ");
  printListNodes(removeNthFromEnd(head, 2));
  freeListNodes(&head);

  int vals_2[] = {1};
  head = createListNodesFromList(vals_2, sizeof(vals_2) / sizeof(int));

  printf("input(%d): ", 1);
  printListNodes(head);
  printf("output: ");
  printListNodes(removeNthFromEnd(head, 1));
  freeListNodes(&head);

  return 0;
}
