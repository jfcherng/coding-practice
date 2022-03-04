#include "_leetcode_common.h"
#include "uthash.h"

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////
// linked list //
/////////////////

struct ListNode *createListNode(const int val) {
  struct ListNode *node = (struct ListNode *) malloc(sizeof(*node));
  node->val = val;
  node->next = NULL;
  return node;
}

void freeListNodes(struct ListNode **headp) {
  for (struct ListNode *p = *headp, *tmp = NULL; p;) {
    tmp = p;
    p = p->next;
    free(tmp);
  }
  *headp = NULL;
}

struct ListNode *createListNodesFromList(const int *vals, const int n) {
  struct ListNode *head = NULL, **pp = &head;
  for (int i = 0; i < n; ++i) {
    *pp = createListNode(vals[i]);
    pp = &((*pp)->next);
  }
  return head;
}

///////////
// debug //
///////////

void printList(const int *list, int size) {
  printf(size ? "[ " : "[");
  while (size-- > 0) {
    printf("%d", *list);
    if (size) {
      printf(", ");
    }
    ++list;
  }
  printf(" ]\n");
}

void printListNodes(struct ListNode const *head) {
  while (head) {
    printf("%d -> ", head->val);
    head = head->next;
  }
  printf("NULL\n");
}
