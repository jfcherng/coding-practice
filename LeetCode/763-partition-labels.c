#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int *partitionLabels(char *s, int *returnSize) {
  // if we have "abc...xyz", the length of the output would be 26
  int *res = calloc(26, sizeof(*res));
  int resIdx = -1;
  int len = strlen(s);

  int last[26] = {0};
  for (int i = 0; i < len; ++i)
    last[s[i] - 'a'] = i;

  int l = 0, r = 0;
  for (int i = 0; i < len; ++i) {
    r = MAX(r, last[s[i] - 'a']);
    if (i == r) {
      res[++resIdx] = r - l + 1;
      l = r + 1;
    }
  }

  *returnSize = resIdx + 1;
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
