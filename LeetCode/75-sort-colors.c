#include "_leetcode_common.h"

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quick_sort(int *nums, int l, int r) {
  if (l >= r)
    return;

  int a = l, b = r - 1;
  int pivot = r; // last element as the pivot

  while (a <= b) {
    while (a <= b && nums[a] <= nums[pivot])
      ++a;
    while (a <= b && nums[b] >= nums[pivot])
      --b;
    if (a < b)
      swap(&nums[a], &nums[b]);
  }

  swap(&nums[a], &nums[pivot]);
  quick_sort(nums, l, a - 1);
  quick_sort(nums, a + 1, r);
}

void sortColors(int *nums, int numsSize) {
  quick_sort(nums, 0, numsSize - 1);
}

int main(int argc, char *argv[]) {
  return 0;
}
