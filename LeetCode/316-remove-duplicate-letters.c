#include "_leetcode_common.c"

char *removeDuplicateLetters(char *s) {
  int len = strlen(s), counter[128] = {0}, inRes[128] = {0};

  char *res = calloc(len + 1, sizeof(*res));
  int resIdx = -1; // stack

  for (int i = 0; i < len; ++i)
    ++counter[s[i]];

  for (int i = 0; i < len; ++i) {
    --counter[s[i]];

    if (inRes[s[i]])
      continue;

    while (resIdx != -1 && res[resIdx] >= s[i] && counter[res[resIdx]] > 0) {
      inRes[res[resIdx]] = false;
      --resIdx;
    }
    inRes[s[i]] = true;
    res[++resIdx] = s[i];
  }

  res[++resIdx] = '\0';
  return res;
}

int main(int argc, char *argv[]) {
  char *res = NULL;

  res = removeDuplicateLetters("cbacdcbc");
  printf("res = %s\n", res);

  return 0;
}
