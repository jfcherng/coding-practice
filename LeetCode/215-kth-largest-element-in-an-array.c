#include "_leetcode_common.c"

#define SWAP(a, b)                                                                                                     \
  {                                                                                                                    \
    int tmp = a;                                                                                                       \
    a = b;                                                                                                             \
    b = tmp;                                                                                                           \
  }

int partition(int *nums, int numsSize, int k, int a, int b) {
  int l = a, r = b - 1, pivot = b; // last element as pivot

  // let left part be less than the pivot, right part be larger then the pivot
  while (l <= r) {
    while (l <= r && nums[l] <= nums[pivot])
      ++l;
    while (l <= r && nums[r] >= nums[pivot])
      --r;
    if (l < r)
      SWAP(nums[l], nums[r]);
  }
  SWAP(nums[l], nums[pivot]);

  return l; // `pivot` is at `l`
}

int findKthLargest(int *nums, int numsSize, int k) {
  // `k` largest = `numsSize + 1 - k` smallest
  int s = numsSize + 1 - k; // let's find sth smallest

  int idx = -1, a = 0, b = numsSize - 1;
  while (true) {
    idx = partition(nums, numsSize, s, a, b);
    // kth largest is at the left part
    if (idx > s - 1)
      b = idx - 1;
    // kth largest is at the right part
    else if (idx < s - 1)
      a = idx + 1;
    // found!!!
    else
      break;
  }

  return nums[idx];
}

int main(int argc, char *argv[]) {
  int arr_1[] = {3, 2, 1, 5, 6, 4}, k_1 = 2;
  int res_1 = findKthLargest(arr_1, sizeof(arr_1) / sizeof(int), k_1);
  printf("res_1 = %d (5)\n", res_1);
  int arr_2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k_2 = 4;
  int res_2 = findKthLargest(arr_2, sizeof(arr_2) / sizeof(int), k_2);
  printf("res_2 = %d (4)\n", res_2);

  return 0;
}
