#include "_leetcode_common.h"

typedef struct {
  int sum;
  int cnt;
  UT_hash_handle hh;
} Counter;

Counter *createNewCounter(int sum, int cnt) {
  Counter *c = malloc(sizeof(*c));
  c->sum = sum;
  c->cnt = cnt;
  return c;
}

int fourSumCount(int *nums1, int nums1Size, int *nums2, int nums2Size, int *nums3, int nums3Size, int *nums4,
                 int nums4Size) {
  int res = 0;
  Counter *out, *pool = NULL;

  for (int i = 0; i < nums1Size; ++i) {
    for (int j = 0; j < nums2Size; ++j) {
      int sum = nums1[i] + nums2[j];
      HASH_FIND_INT(pool, &sum, out);
      if (out) {
        ++out->cnt;
      } else {
        out = createNewCounter(sum, 1);
        HASH_ADD_INT(pool, sum, out);
      }
    }
  }

  for (int i = 0; i < nums3Size; ++i) {
    for (int j = 0; j < nums4Size; ++j) {
      int target = 0 - (nums3[i] + nums4[j]);

      HASH_FIND_INT(pool, &target, out);
      if (out) {
        res += out->cnt;
      }
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
