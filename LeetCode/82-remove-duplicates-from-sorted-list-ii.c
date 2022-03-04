#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode **pp = &head, *last = NULL;

  while (*pp) {
    // make "last" points to the last duplicate node
    for (last = *pp; last->next && last->next->val == (*pp)->val; last = last->next)
      ;

    // no duplicate
    if (*pp == last) {
      pp = &(last->next);
    }
    // delete duplicates
    else {
      while (*pp != last->next) {
        // struct ListNode *tmp = *pp;
        *pp = (*pp)->next;
        // free(tmp);
      }
    }
  }

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *head = NULL;

  int list_1[] = {1, 2, 3, 3, 4, 5, 5};
  head = createListNodesFromList(list_1, sizeof(list_1) / sizeof(int));
  printf("input: ");
  printListNodes(head);
  printf("output: ");
  printListNodes(deleteDuplicates(head));
  printf("\n");
  freeListNodes(&head);

  int list_2[] = {1, 1, 1, 2, 3};
  head = createListNodesFromList(list_2, sizeof(list_2) / sizeof(int));
  printf("input: ");
  printListNodes(head);
  printf("output: ");
  printListNodes(deleteDuplicates(head));
  printf("\n");
  freeListNodes(&head);

  return 0;
}
