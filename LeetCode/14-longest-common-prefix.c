#include "_leetcode_common.h"

char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize <= 0)
    return "\0";

  char *str, *cmp = strs[0];
  int longest_len = strlen(cmp);
  for (int i = 1; i < strsSize; ++i) {
    str = strs[i]; // shorthand
    int j = 0;
    for (; j < longest_len; ++j) {
      if (!str[j] || str[j] != cmp[j]) {
        break;
      }
    }
    longest_len = j;
  }

  char *ans = malloc((longest_len + 1) * sizeof(*ans));
  strncpy(ans, strs[0], longest_len);
  ans[longest_len] = '\0';

  return ans;
}

int main(int argc, char *argv[]) {
  char _strings_1[3][200] = {"flower", "flow", "flight"};
  char **strings_1 = malloc(3 * sizeof(char *));
  strings_1[0] = _strings_1[0];
  strings_1[1] = _strings_1[1];
  strings_1[2] = _strings_1[2];

  printf("longestCommonPrefix(1) = %s\n", longestCommonPrefix(strings_1, 3));

  return 0;
}
