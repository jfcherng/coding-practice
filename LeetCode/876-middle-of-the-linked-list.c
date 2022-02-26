#include "_leetcode_common.c"

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main(int argc, char *argv[]) {
  return 0;
}
