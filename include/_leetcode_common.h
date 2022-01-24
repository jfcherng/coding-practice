#include "uthash.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void printListNode(struct ListNode *head) {
  while (head) {
    printf("%d -> ", head->val);
    head = head->next;
  }
  printf("\n");
}
