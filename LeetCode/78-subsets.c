#include "_leetcode_common.c"

// determinate whether the `n`th bit in `x` is 1
#define nthBit(x, n) (((x) >> (n)) & 1)

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
  const int total = 1 << numsSize;

  int **res = malloc(total * sizeof(*res));
  *returnColumnSizes = malloc(total * sizeof(**returnColumnSizes));
  *returnSize = 0;

  // loop from 000 to 111 (8 iterations)
  for (int i = 0; i < total; ++i) {
    int *sub = malloc(numsSize * sizeof(*res));
    int sub_idx = 0;

    // check whether we take jth digit
    for (int j = 0; j < numsSize; ++j) {
      // taken
      if (nthBit(i, j)) {
        sub[sub_idx++] = nums[j];
      }
    }

    (*returnColumnSizes)[*returnSize] = sub_idx;
    sub = realloc(sub, sub_idx * sizeof(*sub)); // not necessary, but may save some memory
    res[(*returnSize)++] = sub;
  }

  return res;
}
