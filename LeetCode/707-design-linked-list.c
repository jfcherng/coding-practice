#include "_leetcode_common.c"

typedef struct tag_MyLinkedListNode MyLinkedListNode;
struct tag_MyLinkedListNode {
  int val;
  MyLinkedListNode *next;
};

typedef struct {
  int length;
  MyLinkedListNode *head;
} MyLinkedList;

MyLinkedListNode *myLinkedListNodeCreate(int val, MyLinkedListNode *next) {
  MyLinkedListNode *node = malloc(sizeof(*node));
  node->val = val;
  node->next = next;
  return node;
}

MyLinkedList *myLinkedListCreate() {
  MyLinkedList *list = malloc(sizeof(*list));
  list->head = NULL;
  list->length = 0;
  return list;
}

int myLinkedListGet(MyLinkedList *obj, int index) {
  MyLinkedListNode *node = obj->head;
  for (; node && index--; node = node->next)
    ;
  return node ? node->val : -1;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
  if (index < 0 || index > obj->length)
    return;

  ++obj->length;
  MyLinkedListNode **pp = &(obj->head);
  while (index--)
    pp = &((*pp)->next);
  *pp = myLinkedListNodeCreate(val, *pp);
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
  myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
  myLinkedListAddAtIndex(obj, obj->length, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
  if (index < 0 || index >= obj->length)
    return;

  --obj->length;
  MyLinkedListNode **pp = &(obj->head);
  while (index--)
    pp = &((*pp)->next);
  MyLinkedListNode *node = *pp;
  *pp = node->next;
  free(node);
}

void myLinkedListFree(MyLinkedList *obj) {
  // free list nodes
  while (obj->head) {
    MyLinkedListNode *node = obj->head;
    obj->head = node->next;
    free(node);
  }
  // free container
  free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

int main(int argc, char *argv[]) {
  return 0;
}
