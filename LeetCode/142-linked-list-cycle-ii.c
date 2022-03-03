#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Floyd Cycle Detection Algorithm
struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;

  while (1) {
    if (!fast || !fast->next)
      return NULL;

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      break;
  }

  fast = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}

int main(int argc, char *argv[]) {
  return 0;
}
