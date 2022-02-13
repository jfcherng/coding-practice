#include "_leetcode_common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
  const int total = 1 << numsSize;
  *returnSize = total;

  int **res = malloc(total * sizeof(*res));
  *returnColumnSizes = malloc(total * sizeof(**returnColumnSizes));

  int res_idx = 0;
  // loop from 000 to 111 (8 iterations)
  for (int i = 0; i < total; ++i) {
    int *sub = malloc(numsSize * sizeof(*res));
    int sub_idx = 0;

    for (int j = 0; j < numsSize; ++j) {
      // taken
      if ((i >> j) & 1) {
        sub[sub_idx++] = nums[j];
      }
    }
    (*returnColumnSizes)[res_idx] = sub_idx;

    // not necessary, but may save some memory
    sub = realloc(sub, sub_idx * sizeof(*sub));

    res[res_idx++] = sub;
  }

  return res;
}
