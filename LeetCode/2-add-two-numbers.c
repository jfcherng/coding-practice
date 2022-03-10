#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *head = NULL, **pp = &head;

  int carry = 0;
  while (l1 || l2 || carry) {
    int digit = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    if (digit > 9) {
      carry = 1;
      digit -= 10;
    } else {
      carry = 0;
    }

    struct ListNode *node = malloc(sizeof(*node));
    node->val = digit;
    node->next = NULL;

    *pp = node;
    pp = &(node->next);

    l1 = l1 ? l1->next : NULL;
    l2 = l2 ? l2->next : NULL;
  }

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *a = NULL, *b = NULL, *res = NULL;

  int l1_1[] = {2, 4, 3}, l2_1[] = {5, 6, 4};
  a = createListNodesFromList(l1_1, sizeof(l1_1) / sizeof(int));
  b = createListNodesFromList(l2_1, sizeof(l2_1) / sizeof(int));
  res = addTwoNumbers(a, b);
  printListNodes(res); // 7 -> 0 -> 8 -> NULL
  free(a);
  free(b);
  free(res);

  return 0;
}
