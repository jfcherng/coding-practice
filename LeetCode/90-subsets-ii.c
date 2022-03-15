#include "_leetcode_common.c"

// determinate whether the `n`th bit in `x` is 1
#define nthBit(x, n) (((x) >> (n)) & 1)

int sorter(const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
  const int total = 1 << numsSize; // lazy

  // sort for de-duplication
  qsort(nums, numsSize, sizeof(*nums), sorter);

  int **res = malloc(total * sizeof(*res));
  *returnColumnSizes = malloc(total * sizeof(**returnColumnSizes));
  *returnSize = 0;

  // loop from 000 to 111 (8 iterations)
  for (int i = 0; i < total; ++i) {
    int *sub = malloc(numsSize * sizeof(*res));
    int sub_idx = 0;

    // is `i` mapped into a duplicate combination?
    bool isDuplicate = false;
    // check whether we take jth digit
    for (int j = 0; j < numsSize; ++j) {
      // taken
      if (nthBit(i, j)) {
        // only the one, who has consecutive 1s from LSB to the current bit, is non-duplicate
        if (j > 0 && nums[j] == nums[j - 1] && !nthBit(i, j - 1)) {
          isDuplicate = true;
          break;
        }
        sub[sub_idx++] = nums[j];
      }
    }

    if (isDuplicate) {
      free(sub);
      continue;
    }

    (*returnColumnSizes)[*returnSize] = sub_idx;
    sub = realloc(sub, sub_idx * sizeof(*sub)); // not necessary, but may save some memory
    res[(*returnSize)++] = sub;
  }

  return res;
}
