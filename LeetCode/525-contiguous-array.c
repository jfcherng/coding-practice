#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
  int sum; // key
  int idx;
  UT_hash_handle hh;
} Counter;

Counter *createNewCounter(int sum, int idx) {
  Counter *new = malloc(sizeof(*new));
  new->sum = sum;
  new->idx = idx;
  return new;
}

int findMaxLength(int *nums, int numsSize) {
  int res = 0;

  Counter *out, *pool = NULL;
  int sum = 0;

  out = createNewCounter(0, -1);
  HASH_ADD_INT(pool, sum, out);

  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i] == 0 ? -1 : 1;

    HASH_FIND_INT(pool, &sum, out);
    if (out) {
      res = MAX(res, i - out->idx);
    } else {
      out = createNewCounter(sum, i);
      HASH_ADD_INT(pool, sum, out);
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums_[] = {0, 1, 1, 0, 1, 1, 1, 0};
  int *nums = &nums_[0];

  printf("findMaxLength = %d (gold = %d)\n", findMaxLength(nums, sizeof(nums_) / sizeof(int)), 4);

  return 0;
}
