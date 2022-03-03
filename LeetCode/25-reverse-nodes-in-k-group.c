#include "_leetcode_common.c"
#include <stdio.h>

// 206-reverse-linked-list.c
struct ListNode *reverseList(struct ListNode *head, struct ListNode *end) {
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

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
  struct ListNode *curr = head, *end = head, **start = &head;

  while (1) {
    // make sure there are at least k nodes in the rest
    int cnt = 0;
    while (cnt < k && end) {
      end = end->next;
      ++cnt;
    }

    if (cnt < k)
      break;

    *start = reverseList(curr, end);
    start = &(curr->next);

    curr = end;
  }

  return head;
}

int main(int argc, char *argv[]) {
  int nums1[] = {1, 2, 3, 4, 5};
  struct ListNode *list1 = createListNodesFromList(nums1, sizeof(nums1) / sizeof(int));
  struct ListNode *res1 = reverseKGroup(list1, 2);
  printListNodes(res1);
  free(list1);
  free(res1);

  return 0;
}
