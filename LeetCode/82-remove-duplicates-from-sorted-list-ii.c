#include "_leetcode_common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode dummy = {.next = head};
  struct ListNode *prev = &dummy; // last non-duplicate node

  while (head) {
    // has duplicate?
    if (head->next && head->val == head->next->val) {
      // let head points to the last duplicate node
      while (head->next && head->val == head->next->val) {
        head = head->next;
      }
      // skip duplicate nodes
      prev->next = head->next;
    } else {
      prev = prev->next;
    }

    head = head->next;
  }

  return dummy.next;
}

int main(int argc, char *argv[]) {
  struct ListNode n8 = {.val = 5, .next = NULL};
  struct ListNode n7 = {.val = 5, .next = &n8};
  struct ListNode n6 = {.val = 4, .next = &n7};
  struct ListNode n5 = {.val = 4, .next = &n6};
  struct ListNode n4 = {.val = 3, .next = &n5};
  struct ListNode n3 = {.val = 3, .next = &n4};
  struct ListNode n2 = {.val = 2, .next = &n3};
  struct ListNode n1 = {.val = 1, .next = &n2};
  struct ListNode *headn = &n1;

  printf("input: ");
  printListNode(headn);
  printf("output: ");
  printListNode(deleteDuplicates(headn));

  struct ListNode a5 = {.val = 3, .next = NULL};
  struct ListNode a4 = {.val = 2, .next = &a5};
  struct ListNode a3 = {.val = 1, .next = &a4};
  struct ListNode a2 = {.val = 1, .next = &a3};
  struct ListNode a1 = {.val = 1, .next = &a2};
  struct ListNode *heada = &a1;

  printf("input: ");
  printListNode(heada);
  printf("output: ");
  printListNode(deleteDuplicates(heada));

  return 0;
}
