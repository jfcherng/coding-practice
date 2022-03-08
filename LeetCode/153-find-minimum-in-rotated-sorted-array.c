#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int findMin(int *nums, int numsSize) {
  int res = nums[0];

  int l = 0, r = numsSize - 1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    res = MIN(res, nums[mid]);

    // l~mid is sorted
    if (nums[l] < nums[mid]) {
      res = MIN(res, nums[l]);
      l = mid + 1;
    }
    // mid~r is sorted
    else {
      if (mid < numsSize - 1)
        res = MIN(res, nums[mid + 1]);
      r = mid - 1;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
