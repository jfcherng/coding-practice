#include "_leetcode_common.c"

typedef struct {
  int sum;
  int cnt;
  UT_hash_handle hh;
} PrefixSumCounter;

PrefixSumCounter *createPrefixSumCounter(int sum, int cnt) {
  PrefixSumCounter *out = malloc(sizeof(*out));
  out->sum = sum;
  out->cnt = cnt;
  return out;
}

int subarraySum(int *nums, int numsSize, int k) {
  if (numsSize <= 0)
    return 0;

  int res = 0;

  PrefixSumCounter *out, *pool = NULL;
  out = createPrefixSumCounter(0, 1);
  HASH_ADD_INT(pool, sum, out);

  int prefix_sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    prefix_sum += nums[i];

    // define prefix_sum[i] = nums[0] + ... + nums[i]
    // then a subarray sum = nums[a] + ... + nums[b] = prefix_sum[b+1] - prefix_sum[a] = k
    // where we are now the "b+1" and want to find a "a"
    // target = prefix_sum[a] = k - prefix_sum[b+1]
    int target = prefix_sum - k;
    HASH_FIND_INT(pool, &target, out);
    if (out) {
      res += out->cnt;
    }

    // add/update prefix sum hash map
    HASH_FIND_INT(pool, &prefix_sum, out);
    if (out) {
      ++out->cnt;
    } else {
      out = createPrefixSumCounter(prefix_sum, 1);
      HASH_ADD_INT(pool, sum, out);
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  int _n1[] = {1, 2, 3};
  int *n1 = &n1[0];

  int res = subarraySum(_n1, 3, 3);
  printf("res = %d\n", res);

  return 0;
}
