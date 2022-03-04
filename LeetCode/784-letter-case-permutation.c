#include "_leetcode_common.c"

void bt(char *s, int idx, int sLen, char **res, int *returnSize) {
  if (idx >= sLen) {
    char *tmp = calloc(sLen + 1, sizeof(*tmp));
    strcpy(tmp, s);
    res[(*returnSize)++] = tmp;
    return;
  }

  // visit current
  bt(s, idx + 1, sLen, res, returnSize);
  // visit toggled
  if (isalpha(s[idx])) {
    s[idx] ^= 0x20; // toggle case trick
    bt(s, idx + 1, sLen, res, returnSize);
    s[idx] ^= 0x20;
  }
}

char **letterCasePermutation(char *s, int *returnSize) {
  int sLen = 0, letterCnt = 0;
  for (int i = 0; s[i]; ++i) {
    ++sLen;
    if (isalpha(s[i]))
      ++letterCnt;
  }

  *returnSize = 0;
  char **res = calloc(1 << letterCnt, sizeof(*res));
  bt(s, 0, sLen, res, returnSize);
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
