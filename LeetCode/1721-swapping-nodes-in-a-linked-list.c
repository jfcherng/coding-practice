#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swapNodes(struct ListNode *head, int k) {
  struct ListNode **pp = &head, **p1 = &head, **p2 = &head;
  bool isP2BeforeP1 = true;

  // find kth node from head as `*p1`
  while (--k)
    pp = &((*pp)->next);
  p1 = pp;
  pp = &((*pp)->next);

  // find kth node from tail as `*p2`
  while (*pp) {
    pp = &((*pp)->next);
    if (p1 == p2)
      isP2BeforeP1 = false;
    p2 = &((*p2)->next);
  }

  // assume that `p1` is not after `p2`
  if (isP2BeforeP1) {
    pp = p1;
    p1 = p2;
    p2 = pp;
  }

  // swap `*p1` and `*p2`
  struct ListNode *tmp2 = *p2, *tmp2N = (*p2)->next;
  tmp2->next = (*p1)->next != tmp2 ? (*p1)->next : *p1;
  *p2 = *p1;
  (*p1)->next = tmp2N;
  *p1 = tmp2;

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *head;
  int k;

  int vals_0[] = {7, 8};
  //              ^  ^
  //              2  1
  k = 2;
  head = createListNodesFromList(vals_0, sizeof(vals_0) / sizeof(int));
  printf("input(%d): ", k);
  printListNodes(head);
  printf("output: ");
  printListNodes(swapNodes(head, k));
  freeListNodes(&head);

  int vals_1[] = {1, 2, 3, 4, 5};
  //                 ^     ^
  //                 1     2
  k = 2;
  head = createListNodesFromList(vals_1, sizeof(vals_1) / sizeof(int));
  printf("input(%d): ", k);
  printListNodes(head);
  printf("output: ");
  printListNodes(swapNodes(head, k));
  freeListNodes(&head);

  int vals_2[] = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
  //                          ^  ^
  //                          1  2
  k = 5;
  head = createListNodesFromList(vals_2, sizeof(vals_2) / sizeof(int));
  printf("input(%d): ", k);
  printListNodes(head);
  printf("output: ");
  printListNodes(swapNodes(head, k));
  freeListNodes(&head);

  return 0;
}
