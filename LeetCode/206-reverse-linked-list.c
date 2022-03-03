#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList2(struct ListNode *head, struct ListNode *end) {
  if (!head)
    return NULL;

  struct ListNode *prev = end, *curr = head, *tmp = NULL;

  while (curr != end) {
    tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  return prev;
}

struct ListNode *reverseList(struct ListNode *head) {
  return reverseList2(head, NULL);
}

int main(int argc, char *argv[]) {
  return 0;
}
