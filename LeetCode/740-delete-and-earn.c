#include "_leetcode_common.c"
#include <corecrt_malloc.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
  int num;
  int point;
  UT_hash_handle hh;
} Num;

int sorter(const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

int deleteAndEarn(int *nums, int numsSize) {
  Num *out, *pool = NULL;

  int *uniqNums = malloc(numsSize * sizeof(*uniqNums));
  int uniqNumsSize = 0;

  // sum up same numbers with its own total points
  for (int i = 0; i < numsSize; ++i) {
    HASH_FIND_INT(pool, &nums[i], out);
    if (out) {
      out->point += nums[i];
    } else {
      Num *newNum = malloc(sizeof(*newNum));
      newNum->num = nums[i];
      newNum->point = nums[i];
      HASH_ADD_INT(pool, num, newNum);

      uniqNums[uniqNumsSize++] = nums[i];
    }
  }

  qsort(uniqNums, uniqNumsSize, sizeof(*uniqNums), sorter);

  int prev = 0, curr = 0;
  for (int i = 0; i < uniqNumsSize; ++i) {
    HASH_FIND_INT(pool, &uniqNums[i], out);
    // cannot take this num if it's a neighbor of the previous one
    int newCurr = i > 0 && uniqNums[i] - 1 == uniqNums[i - 1]
                      // ... just for clang-format
                      ? MAX(prev + out->point, curr)
                      : curr + out->point;
    prev = curr;
    curr = newCurr;
  }

  return curr;
}

int main(int argc, char *argv[]) {
  return 0;
}
