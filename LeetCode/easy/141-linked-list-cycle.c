#include "uthash.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode *fast = head, *slow = head;

  while (!fast || !fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }

  return false;
}

int main(int argc, char *argv[]) {
  return 0;
}
