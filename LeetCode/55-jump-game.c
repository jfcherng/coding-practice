#include "_leetcode_common.c"

bool canJump(int *nums, int numsSize) {
  // rest of steps we can move
  int move = 1;

  for (int i = 0; i < numsSize; ++i) {
    if (--move < 0)
      return false;
    if (move < nums[i])
      move = nums[i];
  }

  return true;
}

int main(int argc, char *argv[]) {
  return 0;
}
