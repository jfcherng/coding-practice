#include "_leetcode_common.c"

static inline void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int quickSelect(int *nums, int numsSize, int k, int a, int b) {
  int l = a, r = b - 1, pivot = b; // last element as pivot

  // let left part be less than the pivot, right part be larger then the pivot
  while (l <= r) {
    while (l <= r && nums[l] <= nums[pivot])
      ++l;
    while (l <= r && nums[r] >= nums[pivot])
      --r;
    if (l < r)
      swap(&nums[l], &nums[r]);
  }
  swap(&nums[l], &nums[pivot]);
  // now `pivot` is at `l`

  // kth largest is at the left part
  if (l > k - 1)
    return quickSelect(nums, numsSize, k, a, l - 1);
  // kth largest is at the right part
  if (l < k - 1)
    return quickSelect(nums, numsSize, k, l + 1, b);

  return l;
}

int findKthLargest(int *nums, int numsSize, int k) {
  // `k` largest = `numsSize + 1 - k` smallest
  return nums[quickSelect(nums, numsSize, numsSize + 1 - k, 0, numsSize - 1)];
}

int main(int argc, char *argv[]) {
  // int arr_1[] = {3, 2, 1, 5, 6, 4}, k_1 = 2;
  // int res_1 = findKthLargest(arr_1, sizeof(arr_1) / sizeof(int), k_1);
  // printf("res_1 = %d\n", res_1);
  int arr_2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k_2 = 4;
  int res_2 = findKthLargest(arr_2, sizeof(arr_2) / sizeof(int), k_2);
  printf("res_2 = %d\n", res_2);

  return 0;
}
