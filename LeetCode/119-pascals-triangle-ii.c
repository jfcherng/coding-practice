#include "_leetcode_common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize) {
  *returnSize = rowIndex + 1;
  int *res = malloc(*returnSize * sizeof(*res));
  res[0] = 1;

  // i-th row
  for (int i = 1; i <= rowIndex; ++i) {
    // fill boundaries
    res[0] = res[i] = 1;
    // fill mid
    int bak_l = res[0], bak_r;
    for (int j = 1; j < i; ++j) {
      bak_r = res[j];
      res[j] = bak_l + bak_r;
      bak_l = bak_r;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
