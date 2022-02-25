#include "_leetcode_common.c"

char *reverseWords(char *s) {
  int len = strlen(s), l = 0, r = 0; // reverse [l..r]

  while (r < len) {
    // "r" stops at NULL or " "
    while (s[r] && s[r] != ' ')
      ++r;
    --r;
    int next = r + 2;
    // reverse [l..r]
    while (l < r) {
      char tmp = s[l];
      s[l++] = s[r];
      s[r--] = tmp;
    }
    l = r = next;
  }

  return s;
}

int main(int argc, char *argv[]) {
  return 0;
}
