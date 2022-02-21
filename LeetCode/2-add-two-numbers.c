#include "_leetcode_common.c"

void print_list(char *name, struct ListNode *head) {
  printf("%s: ", name);
  printListNodes(head);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *head = malloc(sizeof(*head));
  struct ListNode *curr = head;

  int carry = 0;
  while (l1 || l2 || carry) {
    int digit = carry;
    if (l1)
      digit += l1->val;
    if (l2)
      digit += l2->val;

    if (digit > 9) {
      carry = 1;
      digit -= 10;
    } else {
      carry = 0;
    }

    struct ListNode *node = malloc(sizeof(*node));
    node->val = digit;
    node->next = NULL;

    curr->next = node;
    curr = node;

    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }

  return head->next;
}

int main(int argc, char *argv[]) {
  int l1_1[] = {2, 4, 3}, l2_2[] = {5, 6, 4};

  struct ListNode a1_1 = {.val = 2};
  struct ListNode a2_1 = {.val = 4};
  struct ListNode a3_1 = {.val = 3};
  a1_1.next = &a2_1;
  a2_1.next = &a3_1;
  a3_1.next = NULL;

  struct ListNode b1_1 = {.val = 5};
  struct ListNode b2_1 = {.val = 6};
  struct ListNode b3_1 = {.val = 4};
  b1_1.next = &b2_1;
  b2_1.next = &b3_1;
  b3_1.next = NULL;

  struct ListNode *ans1 = addTwoNumbers(&a1_1, &b1_1);

  print_list("ans1", ans1);

  return 0;
}
