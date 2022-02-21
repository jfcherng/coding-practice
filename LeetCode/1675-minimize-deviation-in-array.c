#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define IS_ODD(n) (n & 1)
#define SWAP_INT_PTR(a, b)                                                                                             \
  {                                                                                                                    \
    int tmp = *(a);                                                                                                    \
    *(a) = *(b);                                                                                                       \
    *(b) = tmp;                                                                                                        \
  }

#define HEAP_OFFSET (1)
typedef int (*heapItemComparator)(int *, int *);

int cmpMaxHeap(int *a, int *b) {
  return *b - *a;
}

bool isRightLeafSmaller(int *heap, int len, int idx, heapItemComparator cmp) {
  int rIdx = idx * 2 + 1; // 1-base index of the right leaf
  return rIdx <= len && cmp(heap + (rIdx - HEAP_OFFSET), heap + (rIdx - HEAP_OFFSET) - 1) <= 0;
}

void _heapBubbleRoot(int *heap, int len, heapItemComparator cmp) {
  for (int i = 1; i * 2 <= len /* has left child */;) {
    int childIdx = isRightLeafSmaller(heap, len, i, cmp) ? (2 * i + 1) : (2 * i);
    if (cmp(heap + (i - HEAP_OFFSET), heap + (childIdx - HEAP_OFFSET)) <= 0) {
      break;
    }
    SWAP_INT_PTR(heap + (i - HEAP_OFFSET), heap + (childIdx - HEAP_OFFSET));
    i = childIdx;
  }
}

void _heapBubbleLeaf(int *heap, int idx, heapItemComparator cmp) {
  for (int parent = idx / 2; idx > HEAP_OFFSET; idx = parent, parent /= 2) {
    if (cmp(heap + (idx - HEAP_OFFSET), heap + (parent - HEAP_OFFSET)) >= 0) {
      break;
    }
    SWAP_INT_PTR(heap + (idx - HEAP_OFFSET), heap + (parent - HEAP_OFFSET));
  }
}

/**
 * Turn arr into a min heap basing on the cmp comparator.
 */
void heapMake(int *arr, int len, heapItemComparator cmp) {
  for (int i = 2; i <= len; ++i) {
    _heapBubbleLeaf(arr, i, cmp);
  }
}

/**
 * Replace heap root with another value.
 */
void heapReplace(int *heap, int len, int val) {
  heap[0] = val;
  _heapBubbleRoot(heap, len, cmpMaxHeap);
}

int minimumDeviation(int *nums, int numsSize) {
  int res = INT_MAX;

  int min = INT_MAX;
  for (int i = 0; i < numsSize; ++i) {
    // make all nums even
    if (IS_ODD(nums[i])) {
      nums[i] *= 2;
    }
    min = MIN(min, nums[i]);
  }

  // construct max heap
  heapMake(nums, numsSize, cmpMaxHeap);

  while (!IS_ODD(nums[0])) {
    int new = nums[0] / 2;
    heapReplace(nums, numsSize, new);
    min = MIN(min, new);
    res = MIN(res, nums[0] - min);
  }

  return MIN(res, nums[0] - min);
}

int main(int argc, char *argv[]) {
  int res;
  // int n[] = {1, 2, 3, 4};
  int n[] = {4, 1, 5, 20, 3};
  int len = sizeof(n) / sizeof(*n);

  res = minimumDeviation(n, len);
  printf("res = %d\n", res);

  return 0;
}
