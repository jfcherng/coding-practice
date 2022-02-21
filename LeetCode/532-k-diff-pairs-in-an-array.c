#include "_leetcode_common.c"
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

static inline int sorter(const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

int binary_search(int *nums, int target, int l, int r, int *cursor) {
  while (l <= r) {
    int mid = (l + r) / 2;
    *cursor = mid;

    if (nums[mid] < target) {
      l = mid + 1;
    } else if (nums[mid] > target) {
      r = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int findPairs(int *nums, int numsSize, int k) {
  if (numsSize <= 1) {
    return 0;
  }

  int res = 0;

  qsort(nums, numsSize, sizeof(*nums), sorter);
  for (int i = 0, needle = 1; i < numsSize;) {
    // 2-sum problem
    if (binary_search(nums, k + nums[i], needle, numsSize - 1, &needle) >= 0) {
      ++res;
    }
    // move to next distinct num
    while (++i < numsSize && nums[i] == nums[i - 1])
      ;

    needle = MAX(needle, i + 1);
  }

  return res;
}

int main(int argc, char *argv[]) {
  // int nums_1[] = {3, 1, 4, 1, 5};
  // int k_1 = 2;

  // printf("(2) but %d\n", findPairs(nums_1, sizeof(nums_1) / sizeof(int), k_1));

  int nums_2[] = {1, 3, 1, 5, 4};
  int k_2 = 0;

  printf("(1) but %d\n", findPairs(nums_2, sizeof(nums_2) / sizeof(int), k_2));

  // int nums_3[] = {1, 2, 3, 4, 5};
  // int k_3 = 1;

  // printf("(4) but %d\n", findPairs(nums_3, sizeof(nums_3) / sizeof(int), k_3));

  return 0;
}
