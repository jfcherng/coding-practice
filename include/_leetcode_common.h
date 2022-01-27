#include "uthash.h"
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void printList(int *list, int listSize) {
  printf("[ ");
  while (listSize--) {
    printf("%d", *list);
    if (listSize > 0) {
      printf(", ");
    }
    ++list;
  }
  printf(" ]\n");
}

void printListNode(struct ListNode *head) {
  while (head) {
    printf("%d -> ", head->val);
    head = head->next;
    if (!head) {
      printf("NULL");
    }
  }
  printf("\n");
}
