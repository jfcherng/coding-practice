#include "_leetcode_common.h"

char *countAndSay(const int n) {
  if (n == 1) {
    return "1";
  }

  char *prev = countAndSay(n - 1);
  int prevLen = strlen(prev);

  char *res = malloc((prevLen * 2 + 1) * sizeof(*res));
  int resIdx = -1;

  int cursor = 0;
  for (int i = 1; i <= prevLen; ++i) {
    if (i == prevLen || prev[i] != prev[cursor]) {
      res[++resIdx] = '0' + (i - cursor);
      res[++resIdx] = prev[cursor];
      cursor = i;
    }
  }
  res[++resIdx] = '\0';

  if (n > 2)
    free(prev);
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
