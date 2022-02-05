#include "_leetcode_common.h"

typedef int *solution;

int sorter(const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
solution *fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;

  if (numsSize < 4) {
    return NULL;
  }

  qsort(nums, numsSize, sizeof(*nums), sorter);

  int malloc_size_1 = 32;
  int malloc_size_2 = 200;

  solution *ret = malloc(malloc_size_1 * sizeof(*ret));
  solution sols = malloc(malloc_size_2 * 4 * sizeof(*sols));
  *returnColumnSizes = malloc(malloc_size_1 * sizeof(int));

  for (int w = 0; w < numsSize - 3; ++w) {
    // de-duplication
    if (w > 0 && nums[w] == nums[w - 1]) {
      continue;
    }

    // 3sum target
    int target3 = target - nums[w];
    for (int x = w + 1; x < numsSize - 2; ++x) {
      // de-duplication
      if (x > w + 1 && nums[x] == nums[x - 1]) {
        continue;
      }

      // 2sum target
      int target2 = target3 - nums[x];
      int l = x + 1, r = numsSize - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum < target2) {
          ++l;
        } else if (sum > target2) {
          --r;
        }
        // solution found
        else {
          int shift = *returnSize * 4;
          sols[shift + 0] = nums[w];
          sols[shift + 1] = nums[x];
          sols[shift + 2] = nums[l];
          sols[shift + 3] = nums[r];
          ret[*returnSize] = &sols[shift];

          (*returnColumnSizes)[*returnSize] = 4;
          ++*returnSize;

          while (1) {
            ++l;
            if (l >= r || nums[l] != nums[l - 1])
              break;
          }

          if (*returnSize >= malloc_size_1) {
            malloc_size_1 <<= 1;
            ret = realloc(ret, malloc_size_1 * sizeof(*ret));
            *returnColumnSizes = realloc(*returnColumnSizes, malloc_size_1 * sizeof(**returnColumnSizes));
          }
        }
      }
    }
  }

  return ret;
}

int main(int argc, char *argv[]) {
  return 0;
}
