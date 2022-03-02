#include "_leetcode_common.c"

bool isSubsequence(char *s, char *t) {
  for (; *s; ++t) {
    if (!*t)
      return false;
    if (*s == *t)
      ++s;
  }

  return true;
}

int main(int argc, char *argv[]) {
  bool res = isSubsequence("abc", "ahbgdc");
  printf("res = %s\n", res ? "true" : "false");

  return 0;
}
