#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxArea(int *height, int heightSize) {
  int max = 0;
  int l = 0, r = heightSize - 1;

  while (l < r) {
    max = MAX(max, (r - l) * MIN(height[l], height[r]));
    if (height[l] < height[r]) {
      ++l;
    } else {
      --r;
    }
  }

  return max;
}

int main(int argc, char *argv[]) {
  int heights[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  printf("ans_1 = %d (49)\n", maxArea(heights, sizeof(heights) / sizeof(int)));

  return 0;
}
