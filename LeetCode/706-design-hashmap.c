#include "_leetcode_common.c"

#define NONEXISTENT_VALUE (-1)

typedef struct MyHashMapNode MyHashMapNode;
typedef struct MyHashMap MyHashMap;

struct MyHashMapNode {
  int key;
  int value;
  // nodes are in the form of a linked list
  MyHashMapNode *next;
};

struct MyHashMap {
  MyHashMapNode *handle;
};

MyHashMapNode *_myHashMapNodeCreate() {
  MyHashMapNode *obj = malloc(sizeof(*obj));
  obj->next = NULL;
  return obj;
}

MyHashMapNode *_myHashMapFindKey(MyHashMap *obj, int key) {
  MyHashMapNode *node = obj->handle;
  while (node) {
    if (node->key == key)
      return node;
    node = node->next;
  }
  return NULL;
}

void _myHashMapAddNode(MyHashMap *obj, MyHashMapNode *node) {
  MyHashMapNode *tmp = obj->handle;
  obj->handle = node;
  node->next = tmp;
}

MyHashMap *myHashMapCreate() {
  MyHashMap *obj = malloc(sizeof(*obj));
  obj->handle = NULL;
  return obj;
}

void myHashMapPut(MyHashMap *obj, int key, int value) {
  MyHashMapNode *node = _myHashMapFindKey(obj, key);
  if (!node) {
    // prepare node
    node = _myHashMapNodeCreate();
    node->key = key;
    _myHashMapAddNode(obj, node);
  }
  node->value = value;
}

int myHashMapGet(MyHashMap *obj, int key) {
  MyHashMapNode *node = _myHashMapFindKey(obj, key);
  return node ? node->value : NONEXISTENT_VALUE;
}

void myHashMapRemove(MyHashMap *obj, int key) {
  MyHashMapNode **pp = &(obj->handle), *tmp;
  while (*pp) {
    if ((*pp)->key == key) {
      tmp = *pp;
      *pp = (*pp)->next;
      free(tmp);
      break;
    }
    pp = &((*pp)->next);
  }
}

void myHashMapFree(MyHashMap *obj) {
  MyHashMapNode *node = obj->handle, *tmp;
  while (node) {
    tmp = node;
    node = node->next;
    free(tmp);
  }
  free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

int main(int argc, char *argv[]) {
  MyHashMap *obj = myHashMapCreate();
  myHashMapPut(obj, 2, 99);
  int param_2 = myHashMapGet(obj, 2);
  printf("GET: %d\n", param_2);
  myHashMapRemove(obj, 2);
  myHashMapFree(obj);
  return 0;
}
