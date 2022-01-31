#include "_leetcode_common.h"

int findDuplicate(int *nums, int numsSize) {
  int slow = 0, fast = 0;
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  int slow2 = 0;
  while (slow != slow2) {
    slow = nums[slow];
    slow2 = nums[slow2];
  }

  return slow2;
}

int main(int argc, char *argv[]) {
  return 0;
}
