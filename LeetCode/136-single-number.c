#include "_leetcode_common.c"

int singleNumber(int *nums, int numsSize) {
  int res = 0;
  for (int i = 0; i < numsSize; ++i)
    res ^= nums[i];
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
