#include "_leetcode_common.c"

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

bool increasingTriplet(int *nums, int numsSize) {
  int lis = 0; // length of LIS
  // dp[i] is the best end of LIS = i
  // sized 3 since we only want to know whether LIS is >= 3
  int *dp = malloc(3 * sizeof(*dp));

  for (int i = 0; i < numsSize; ++i) {
    // binary search for the first value which is >= nums[i]
    int l = 0, r = lis;
    while (l < r) {
      int mid = l + (r - l) / 2; // avoid overflow
      if (dp[mid] < nums[i])
        l = mid + 1;
      else
        r = mid;
    }

    dp[r] = nums[i];
    if (r == lis)
      ++lis;

    // early return
    if (lis >= 3)
      return true;
  }

  return false;
}

// TLE... time complexity = O(n^2)
bool increasingTriplet_LIS(int *nums, int numsSize) {
  // the length of the Longest Incresing Sequence which ends at index "i"
  int *lis = malloc(numsSize * sizeof(*lis));
  for (int i = 0; i < numsSize; ++i)
    lis[i] = 1; // init

  for (int i = 0; i < numsSize; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        lis[i] = MAX(lis[i], lis[j] + 1);
        if (lis[i] >= 3) {
          return true;
        }
      }
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  return 0;
}

// [20,100,10,12,5,13]: 10, 12, 13
//  20, 21, 22, 0, 1, 5, 27
