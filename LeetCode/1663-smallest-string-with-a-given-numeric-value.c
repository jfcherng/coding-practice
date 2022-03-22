#include "_leetcode_common.c"

char *getSmallestString(int n, int k) {
  char *res = malloc((n + 1) * sizeof(*res));
  // fill results with all 'a's
  memset(res, 'a', n * sizeof(*res));
  res[n] = '\0';
  k -= n;

  for (int i = n - 1; i >= 0; --i) {
    if (k <= 25) {
      res[i] += k;
      break;
    }
    res[i] += 25;
    k -= 25;
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
