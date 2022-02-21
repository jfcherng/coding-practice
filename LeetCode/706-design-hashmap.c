#include "_leetcode_common.c"

#define NONEXISTENT_VALUE (-1)

typedef struct MyHashMap MyHashMap;
struct MyHashMap {
  int key;
  int value;
  MyHashMap *next;
};

MyHashMap *myHashMapCreate() {
  MyHashMap *ret = malloc(sizeof(*ret));
  ret->next = NULL;
  return ret;
}

MyHashMap *myHashMapFindKey(MyHashMap *obj, int key) {
  while (obj) {
    if (obj->key == key) {
      return obj;
    }
    obj = obj->next;
  }
  return NULL;
}

void myHashMapAddNode(MyHashMap *obj, MyHashMap *node) {
  MyHashMap *tmp = obj->next;
  obj->next = node;
  node->next = tmp;
}

void myHashMapPut(MyHashMap *obj, int key, int value) {
  MyHashMap *node = myHashMapFindKey(obj, key);
  if (node) {
    node->value = value;
  } else {
    node = myHashMapCreate();
    node->key = key;
    node->value = value;
    myHashMapAddNode(obj, node);
  }
}

int myHashMapGet(MyHashMap *obj, int key) {
  MyHashMap *node = myHashMapFindKey(obj, key);
  return node ? node->value : NONEXISTENT_VALUE;
}

void myHashMapRemove(MyHashMap *obj, int key) {
  MyHashMap *dummy = myHashMapCreate();
  dummy->next = obj;
  MyHashMap *prev = dummy;
  while (obj) {
    if (obj->key == key) {
      prev->next = obj->next;
      free(obj);
      break;
    }
    prev = obj;
    obj = obj->next;
  }
  free(dummy);
}

void myHashMapFree(MyHashMap *obj) {
  MyHashMap *tmp = myHashMapCreate();
  while (obj) {
    tmp = obj;
    obj = obj->next;
    free(tmp);
  }
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
