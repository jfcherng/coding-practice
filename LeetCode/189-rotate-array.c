#include "_leetcode_common.c"

static inline void reverse(int *arr, int l, int r) {
  // r is inclusive
  while (l < r) {
    int tmp = arr[l];
    arr[l++] = arr[r];
    arr[r--] = tmp;
  }
}

void rotate(int *nums, int numsSize, int k) {
  k %= numsSize;
  reverse(nums, 0, numsSize - k - 1);
  reverse(nums, numsSize - k, numsSize - 1);
  reverse(nums, 0, numsSize - 1);
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 2, 3, 4, 5, 6, 7};
  int numsSize = sizeof(nums) / sizeof(int);
  rotate(nums, numsSize, 0);
  printList(nums, numsSize);

  return 0;
}
