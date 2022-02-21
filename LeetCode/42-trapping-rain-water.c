#include "_leetcode_common.c"

int trap(int *height, int heightSize) {
  // sum of rain+block, and sum of block
  int rb_sum = 0, b_sum = 0;
  int l = 0, r = heightSize - 1;

  // calculate block sum
  for (int i = 0; i < heightSize; ++i) {
    b_sum += height[i];
  }

  // calculate rain+block sum from the lowest row to the highest row
  int base_height = 0;
  while (l <= r) {
    int hl = height[l], hr = height[r];
    int height_min = hl < hr ? hl : hr;

    rb_sum += (height_min - base_height) * (r - l + 1);
    base_height = height_min;

    if (hl <= hr) {
      while (l <= r && height[l] <= base_height)
        ++l;
    }
    if (hl >= hr) {
      while (l <= r && height[r] <= base_height)
        --r;
    }
  }

  return rb_sum - b_sum;
}

int main(int argc, char *argv[]) {
  int heights_1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  printf("ans_1 = %d (6)\n", trap(heights_1, sizeof(heights_1) / sizeof(int)));
  int heights_2[] = {4, 2, 0, 3, 2, 5};
  printf("ans_2 = %d (9)\n", trap(heights_2, sizeof(heights_2) / sizeof(int)));

  return 0;
}
