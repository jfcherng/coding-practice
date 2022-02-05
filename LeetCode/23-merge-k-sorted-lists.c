#include "_leetcode_common.h"
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// LeetCode #21
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *dummy = malloc(sizeof(*dummy));
  struct ListNode *tail = dummy;
  dummy->next = NULL;

  while (list1 && list2) {
    // the list which has a smaller head
    struct ListNode **list = list1->val < list2->val ? &list1 : &list2;
    tail->next = *list;
    *list = (*list)->next;
    // next iteration
    tail = tail->next;
  }

  if (list1) {
    tail->next = list1;
  }
  if (list2) {
    tail->next = list2;
  }

  return dummy->next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0) {
    return NULL;
  }

  while (listsSize > 1) {
    struct ListNode **merged = malloc(5001 * sizeof(*merged));
    int length = 0;
    for (int i = 0; i < listsSize; i += 2) {
      struct ListNode *l1 = lists[i];
      struct ListNode *l2 = i + 1 < listsSize ? lists[i + 1] : NULL;
      merged[length++] = mergeTwoLists(l1, l2);
    }
    // next iteration
    lists = merged;
    listsSize = length;

    printf("listsSize(%d)\n", listsSize);
    for (int i = 0; i < listsSize; ++i) {
      printf("lists[%d]: ", i);
      printListNode(lists[i]);
    }
  }

  return lists[0];
}

int main(int argc, char *argv[]) {
  struct ListNode m1 = {.val = 1};
  struct ListNode m2 = {.val = 4};
  struct ListNode m3 = {.val = 5};
  m1.next = &m2;
  m2.next = &m3;
  m3.next = NULL;

  struct ListNode n1 = {.val = 1};
  struct ListNode n2 = {.val = 3};
  struct ListNode n3 = {.val = 4};
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  struct ListNode o1 = {.val = 2};
  struct ListNode o2 = {.val = 6};
  o1.next = &o2;
  o2.next = NULL;

  int listsSize = 3;
  struct ListNode **lists = malloc(listsSize * sizeof(*lists));
  lists[0] = &m1;
  lists[1] = &n1;
  lists[2] = &o1;

  struct ListNode *res = mergeKLists(lists, listsSize);

  printListNode(res);

  return 0;
}
