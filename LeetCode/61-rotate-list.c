#include "_leetcode_common.c"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head)
    return NULL;

  // get "tail" node and list length
  int len = 1;
  struct ListNode *tail = head;
  while (tail->next) {
    ++len;
    tail = tail->next;
  }

  if (len == 1 || (k %= len) == 0)
    return head;

  // circle the list
  tail->next = head;

  // make move tail be the new tail
  tail = head;
  for (int move = len - k - 1; move; --move)
    tail = tail->next;

  // cut
  head = tail->next;
  tail->next = NULL;

  return head;
}

int main(int argc, char *argv[]) {
  struct ListNode *res = NULL, *list = NULL;
  int k = 0;

  // test 1
  int nums_1[] = {1, 2, 3, 4, 5};
  k = 2;
  list = createListNodesFromList(nums_1, sizeof(nums_1) / sizeof(int));
  res = rotateRight(list, k);
  printListNodes(res);
  freeListNodes(&list);

  // test 2
  int nums_2[] = {1};
  k = 0;
  list = createListNodesFromList(nums_2, sizeof(nums_2) / sizeof(int));
  res = rotateRight(list, k);
  printListNodes(res);
  freeListNodes(&list);

  return 0;
}
