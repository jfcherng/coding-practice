#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int house_robber_1(int *nums, int numsSize) {
  int curr = 0, prev = 0;
  for (int i = 0; i < numsSize; ++i) {
    int newCurr = MAX(curr, prev + nums[i]);
    prev = curr;
    curr = newCurr;
  }

  return curr;
}

int rob(int *nums, int numsSize) {
  // a house is either robbed or not robbed
  //
  //                    / house 0 is robbed => house 1 and n-1 are not robbed => house 2~n-2 is "house robber 1"
  // thus, we can assume
  //                    \ house 0 is not robbed => house 1~n-1 is "house robber 1"
  //
  // by doing so, the circular relationship is break in either assumption.
  return MAX(
      // house 0 is robbed
      nums[0] + house_robber_1(nums + 2, numsSize - 3),
      // house 0 is not robbed
      house_robber_1(nums + 1, numsSize - 1));
}

int main(int argc, char *argv[]) {
  return 0;
}
