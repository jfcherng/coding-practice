#include "_leetcode_common.h"

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
  struct ListNode m1 = {.val = 1};
  struct ListNode m2 = {.val = 2};
  struct ListNode m3 = {.val = 4};
  m1.next = &m2;
  m2.next = &m3;
  m3.next = NULL;

  struct ListNode n1 = {.val = 1};
  struct ListNode n2 = {.val = 3};
  struct ListNode n3 = {.val = 4};
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  struct ListNode *res = mergeTwoLists(&m1, &n1);

  printListNode(res);

  return 0;
}
