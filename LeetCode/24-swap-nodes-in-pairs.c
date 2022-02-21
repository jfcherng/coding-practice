#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swapPairs(struct ListNode *head) {
  struct ListNode **headp = &head, *prev, *curr;

  // "headp" points to the "head" of each iteration
  while ((prev = *headp) && (curr = prev->next)) {
    prev->next = curr->next;
    curr->next = prev;
    *headp = curr;
    // prepare for the next iteration
    headp = &(prev->next);
  }

  return head;
}

int main(int argc, char *argv[]) {
  return 0;
}
