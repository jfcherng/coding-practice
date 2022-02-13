#include "_leetcode_common.h"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *visitor = head;
  while (n > 0 && visitor) {
    visitor = visitor->next;
    --n;
  }

  if (!visitor) {
    // if n == length, means we want to remove the 1st node,
    // so we can directly return the next node.
    //
    // otherwise, node list is too short. nothing to be removed
    return n ? head : head->next;
  }

  struct ListNode *needle = head;
  while (visitor->next) {
    visitor = visitor->next;
    needle = needle->next;
  }

  // skip the next node of the niddle
  needle->next = needle->next->next;

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode n5 = {.val = 5, .next = NULL};
  struct ListNode n4 = {.val = 4, .next = &n5};
  struct ListNode n3 = {.val = 3, .next = &n4};
  struct ListNode n2 = {.val = 2, .next = &n3};
  struct ListNode n1 = {.val = 1, .next = &n2};
  struct ListNode *headn = &n1;

  printf("input(%d): ", 2);
  printListNode(headn);
  printf("output: ");
  printListNode(removeNthFromEnd(headn, 2));

  struct ListNode a1 = {.val = 1, .next = NULL};
  struct ListNode *heada = &a1;

  printf("input(%d): ", 1);
  printListNode(heada);
  printf("output: ");
  printListNode(removeNthFromEnd(heada, 1));

  return 0;
}
