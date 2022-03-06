#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode *head) {
  // we want 12345 to be 15243, which is two lists 123 and 54 interleaving with each other
  if (!head)
    return;

  // split the list from middle into l1 (which is longer) and l2
  struct ListNode *fast = head->next, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  struct ListNode *l1 = head, *l2 = slow->next;
  slow->next = NULL;

  // reverse l2
  struct ListNode *l2_new = NULL;
  while (l2) {
    struct ListNode *tmp = l2_new;
    l2_new = l2;
    l2 = l2->next;
    l2_new->next = tmp;
  }
  l2 = l2_new;

  // merge l1 and l2
  while (l1 && l2) {
    struct ListNode *l1_next = l1->next;
    l1->next = l2;
    l2 = l2->next;
    l1->next->next = l1_next;
    // next iteration
    l1 = l1_next;
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
