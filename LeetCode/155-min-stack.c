#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define STACK_SIZE (30000)

typedef struct {
  // usual value stack
  int items[STACK_SIZE];
  int topIdx;
  // min value stack
  int itemsMin[STACK_SIZE];
  int topIdxMin;
} MinStack;

MinStack *minStackCreate() {
  MinStack *res = malloc(sizeof(*res));
  res->topIdx = res->topIdxMin = -1;
  return res;
}

void minStackPush(MinStack *obj, int val) {
  obj->items[++obj->topIdx] = val;
  obj->itemsMin[++obj->topIdxMin] = obj->topIdxMin == -1 ? val : MIN(val, obj->itemsMin[obj->topIdxMin]);
}

void minStackPop(MinStack *obj) {
  --obj->topIdx;
  --obj->topIdxMin;
}

int minStackTop(MinStack *obj) {
  return obj->items[obj->topIdx];
}

int minStackGetMin(MinStack *obj) {
  return obj->itemsMin[obj->topIdxMin];
}

void minStackFree(MinStack *obj) {
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/

int main(int argc, char *argv[]) {
  return 0;
}
