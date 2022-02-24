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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  while (listsSize > 1) {
    int length = 0;
    for (int i = 0; i < listsSize; i += 2) {
      // in-place merge
      lists[length++] = mergeTwoLists(lists[i], // ...
                                      i + 1 < listsSize ? lists[i + 1] : NULL);
    }
    // next iteration
    listsSize = length;

#ifdef DEBUG
    printf("listsSize(%d)\n", listsSize);
    for (int i = 0; i < listsSize; ++i) {
      printf("lists[%d]: ", i);
      printListNodes(lists[i]);
    }
#endif
  }

  return listsSize ? lists[0] : NULL;
}

int main(int argc, char *argv[]) {
  int l0[] = {1, 4, 5};
  int l1[] = {1, 3, 4};
  int l2[] = {2, 6};
  struct ListNode *lists[] = {
      createListNodesFromList(l0, sizeof(l0) / sizeof(int)),
      createListNodesFromList(l1, sizeof(l1) / sizeof(int)),
      createListNodesFromList(l2, sizeof(l2) / sizeof(int)),
  };

  struct ListNode *res = mergeKLists(lists, sizeof(lists) / sizeof(struct ListNode *));
  printListNodes(res);

  return 0;
}
