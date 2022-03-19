#include "_leetcode_common.c"

#define UNREACHABLE (-1)

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// time complexity = O(n), space complexity = O(1)
int jump(int *nums, int numsSize) {
  int step = 0;

  int l = 0, r = 0;
  while (r < numsSize - 1) {
    int jumpTo = r;
    for (int j = l; j <= r; ++j)
      jumpTo = MAX(jumpTo, nums[j] + j);

    if (jumpTo == r)
      return UNREACHABLE;

    l = r + 1;
    r = jumpTo;
    ++step;
  }

  return step;
}

int main(int argc, char *argv[]) {
  int size = 5;
  int nums_[] = {2, 3, 1, 1, 4};
  int *nums = &nums_[0];

  int ans = jump(nums, size);
  printf("ans(2) = %d\n", ans);

  return 0;
}
