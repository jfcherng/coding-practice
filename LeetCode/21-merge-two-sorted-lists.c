#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *head, **pp = &head, **less;

  for (; l1 && l2; pp = &((*pp)->next)) {
    less = l1->val < l2->val ? &l1 : &l2;
    *pp = *less;
    *less = (*less)->next;
  }
  // either l1 or l2 is NULL (i.e., 0)
  *pp = (struct ListNode *) ((uintptr_t) l1 | (uintptr_t) l2);

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *l1, *l2, *res;

  int v1[] = {1, 2, 4};
  l1 = createListNodesFromList(v1, sizeof(v1) / sizeof(int));
  int v2[] = {1, 3, 4};
  l2 = createListNodesFromList(v2, sizeof(v2) / sizeof(int));
  printf("L1: ");
  printListNodes(l1);
  printf("L2: ");
  printListNodes(l2);
  res = mergeTwoLists(l1, l2);
  printf("res: ");
  printListNodes(res);
  freeListNodes(&l1);
  freeListNodes(&l2);
  freeListNodes(&res);

  return 0;
}
