#include "_leetcode_common.c"

bool isMatch(char *s, char *p) {
  if (!*p)
    return !*s;

  bool isCurrMatched = *s && (*s == *p || *p == '.');

  if (p[1] == '*') {
    return (isCurrMatched && isMatch(s + 1, p)) || // use '*'
           isMatch(s, p + 2)                       // not use '*'
        ;
  }

  return isCurrMatched && isMatch(s + 1, p + 1);
}

int main(int argc, char *argv[]) {
  // bool res = isMatch("ab", ".*c");
  bool res = isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");

  printf("res = %s\n", res ? "true" : "false");

  return 0;
}
