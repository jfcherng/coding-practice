#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define IS_ODD(n) (n & 1)
#define SWAP_INT_BY_PTR(a, b)                                                                                          \
  {                                                                                                                    \
    int tmp = *(a);                                                                                                    \
    *(a) = *(b);                                                                                                       \
    *(b) = tmp;                                                                                                        \
  }

typedef int (*heapItemComparator)(int *, int *);

int cmpMaxHeap(int *a, int *b) {
  return *b - *a;
}

// make heap[idx] satisfies heap property, assuming left/right subtrees are already a heap
void _heapify(int *heap, int idx, int len, heapItemComparator cmp) {
  int minIdx = idx, lIdx = (idx << 1) + 1, rIdx = (idx << 1) + 2;
  if (lIdx < len && cmp(heap + lIdx, heap + minIdx) < 0)
    minIdx = lIdx;
  if (rIdx < len && cmp(heap + rIdx, heap + minIdx) < 0)
    minIdx = rIdx;
  // need swap root with child?
  if (minIdx != idx) {
    SWAP_INT_BY_PTR(heap + idx, heap + minIdx);
    _heapify(heap, minIdx, len, cmp);
  }
}

/**
 * Turn arr into a min heap basing on the cmp comparator.
 */
void heapMake(int *arr, int len, heapItemComparator cmp) {
  for (int i = (len - 1) >> 1; i >= 0; --i)
    _heapify(arr, i, len, cmp);
}

/**
 * Replace heap root with another value.
 */
void heapReplace(int *heap, int len, int val) {
  heap[0] = val;
  _heapify(heap, 0, len, cmpMaxHeap);
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
