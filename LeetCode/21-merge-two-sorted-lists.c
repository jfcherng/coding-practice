#include "_leetcode_common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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
