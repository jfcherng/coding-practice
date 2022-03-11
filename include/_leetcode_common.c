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

struct ListNode *createListNode(const int val, struct ListNode *const next) {
  struct ListNode *node = (struct ListNode *) malloc(sizeof(*node));
  node->val = val;
  node->next = next;
  return node;
}

void freeListNodes(struct ListNode **const headp) {
  for (struct ListNode *p = *headp, *tmp = NULL; p;) {
    tmp = p;
    p = p->next;
    free(tmp);
  }
  *headp = NULL;
}

struct ListNode *createListNodesFromList(const int *const vals, const int n) {
  struct ListNode *head = NULL, **pp = &head;
  for (int i = 0; i < n; ++i) {
    *pp = createListNode(vals[i], NULL);
    pp = &((*pp)->next);
  }
  return head;
}

//////////
// tree //
//////////

struct TreeNode *createTreeNode(const int val, struct TreeNode *const left, struct TreeNode *const right) {
  struct TreeNode *node = (struct TreeNode *) malloc(sizeof(*node));
  node->val = val;
  node->left = left;
  node->right = right;
  return node;
}

struct TreeNode *_createTreeNodesFromListForIdx(const int *const vals, const int n, const int idx) {
  return idx >= n || vals[idx] == TREENODE_NULL
             ? NULL
             : createTreeNode(vals[idx], // ...
                              _createTreeNodesFromListForIdx(vals, n, (idx + 1) * 2 - 1),
                              _createTreeNodesFromListForIdx(vals, n, (idx + 1) * 2));
}

struct TreeNode *createTreeNodesFromList(const int *const vals, const int n) {
  return _createTreeNodesFromListForIdx(vals, n, 0);
}

void freeTreeNodes(struct TreeNode **rootp) {
  if (!*rootp)
    return;
  freeTreeNodes(&((*rootp)->left));
  freeTreeNodes(&((*rootp)->right));
  free(*rootp);
  *rootp = NULL;
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

typedef enum {
  PRINT_PRE_ORDER,
  PRINT_IN_ORDER,
  PRINT_POST_ORDER,
  PRINT_EULERIAN_PATH // print before leaving nodes
} TreePrintType;

void _printTreeNodes(const struct TreeNode *const root, const TreePrintType pt) {
  if (pt == PRINT_PRE_ORDER)
    printf("%d -> ", root->val);
  if (root->left) {
    if (pt == PRINT_EULERIAN_PATH)
      printf("%d -> ", root->val);
    _printTreeNodes(root->left, pt);
  }
  if (pt == PRINT_IN_ORDER)
    printf("%d -> ", root->val);
  if (root->right) {
    if (pt == PRINT_EULERIAN_PATH)
      printf("%d -> ", root->val);
    _printTreeNodes(root->right, pt);
  }
  if (pt == PRINT_POST_ORDER || pt == PRINT_EULERIAN_PATH)
    printf("%d -> ", root->val);
}

void printTreeNodes(const struct TreeNode *const root, const TreePrintType pt) {
  if (pt == PRINT_PRE_ORDER)
    printf("(pre-order) ");
  else if (pt == PRINT_IN_ORDER)
    printf("(in-order) ");
  else if (pt == PRINT_POST_ORDER)
    printf("(post-order) ");
  else if (pt == PRINT_EULERIAN_PATH)
    printf("(Eulerian path) ");
  else
    printf("(unknown-order) ");
  if (root)
    _printTreeNodes(root, pt);
  printf("END\n");
}
