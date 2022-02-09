#include "_leetcode_common.h"

int *grayCode(const int n, int *returnSize) {
  *returnSize = 1 << n;
  int *res = malloc(*returnSize * sizeof(res));

  res[0] = 0;
  for (int cnt = 1, msb = 1; cnt < *returnSize; msb <<= 1) {
    // mirror and add MSB
    for (int i = cnt - 1; i >= 0; --i) {
      res[cnt++] = res[i] | msb;
    }
  }

  return res;
}

// @see
// https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81#%E4%BA%8C%E9%80%B2%E4%BD%8D%E6%95%B8%E8%BD%89%E6%A0%BC%E9%9B%B7%E7%A2%BC
int *grayCode2(const int n, int *returnSize) {
  *returnSize = 1 << n;
  int *res = malloc(*returnSize * sizeof(res));

  for (int i = 0; i < *returnSize; ++i) {
    // G(n) = B(n+1) ^ B(n)
    res[i] = i ^ (i >> 1);
  }

  return res;
}

int main(int argc, char *argv[]) {
  int size = 0;
  int *res = grayCode(5, &size);

  printList(res, size);

  return 0;
}
