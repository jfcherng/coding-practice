#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// LeetCode #21
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

// merge sort: time complexity = O(n log n), space complexity = O(log n)
struct ListNode *sortList(struct ListNode *head) {
  // length < 2
  if (!head || !head->next)
    return head;
  // split into two sub-lists
  struct ListNode *slow = head, *fast = head, *tail;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  tail = slow->next;
  slow->next = NULL;

#ifdef DEBUG
  printf("\n");
  printf("split head: ");
  printListNodes(head);
  printf("split tail: ");
  printListNodes(tail);
  printf("\n");
#endif

  return mergeTwoLists(sortList(head), sortList(tail));
}

// bubble sort: time complexity = O(n^2), space complexity = O(1)
struct ListNode *sortList_bubble_sort(struct ListNode *head) {
  struct ListNode **pp, **n, **nn, *tmp;

  bool isSorted = false;
  while (!isSorted) {
    isSorted = true;
    for (pp = &head; *pp && (*pp)->next; pp = &((*pp)->next)) {
      // swap
      if ((*pp)->val > (*pp)->next->val) {
        isSorted = false;
        tmp = *pp, n = &((*pp)->next), nn = &((*pp)->next->next);
        *pp = *n;
        *n = *nn;
        *nn = tmp;
      }
    }
  }

  return head;
}

int main(int argc, char *argv[]) {
  int l1[] = {4, 2, 1, 3};
  struct ListNode *ln1 = createListNodesFromList(l1, sizeof(l1) / sizeof(int));
  printf("===== Before: ");
  printListNodes(ln1);
  ln1 = sortList(ln1);
  printf("===== After: ");
  printListNodes(ln1);

  return 0;
}
