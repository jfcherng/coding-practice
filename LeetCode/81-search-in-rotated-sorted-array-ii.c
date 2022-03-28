#include "_leetcode_common.c"

bool search(int *nums, int numsSize, int target) {
  int l = 0, r = numsSize - 1;

  while (l < r) {
    int mid = l + (r - l) / 2;

    if (nums[mid] == target)
      return true;

    // left part is sorted
    if (nums[l] < nums[mid]) {
      if (nums[l] <= target && target <= nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    // right part is sorted
    else if (nums[r] > nums[mid]) {
      if (nums[mid] <= target && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    // can't determine (such as {1, 0, 1, 1, 1})
    //                           ^     ^     ^
    //                           l     m     r
    else {
      return search(nums + l, mid - l, target) ||     // left part without mid
             search(nums + mid + 1, r - mid, target); // right part without mid
    }
  }

  return l == r && nums[l] == target;
}

int main(int argc, char *argv[]) {
  int res;

  int nums_1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
  res = search(nums_1, sizeof(nums_1) / sizeof(int), 2);
  printf("res = %d\n", res);

  int nums_2[] = {1, 2, 1};
  res = search(nums_2, sizeof(nums_2) / sizeof(int), 0);
  printf("res = %d\n", res);

  int nums_3[] = {1, 1, 3, 1, 1};
  res = search(nums_3, sizeof(nums_3) / sizeof(int), 0);
  printf("res = %d\n", res);

  return 0;
}
