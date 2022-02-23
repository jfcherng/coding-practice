#include "_leetcode_common.c"

#define CACHE_UNKNOWN (3)

bool dfs(char *s, char *p, int i, int j, char **cache) {
  if (cache[i][j] != CACHE_UNKNOWN)
    return cache[i][j];

  if (!p[j])
    return (cache[i][j] = !s[i]);

  if (s[i] && (s[i] == p[j] || p[j] == '?'))
    return (cache[i][j] = dfs(s, p, i + 1, j + 1, cache));

  if (p[j] == '*') {
    return (cache[i][j] = dfs(s, p, i, j + 1, cache) ||        // not use "*"
                          (s[i] && dfs(s, p, i + 1, j, cache)) // use "*"
    );
  }

  return (cache[i][j] = false);
}

bool isMatch(char *s, char *p) {
  // boring cache init
  int sSize = strlen(s) + 1, pSize = strlen(p) + 1;
  char *cache_ = malloc(sSize * pSize * sizeof(*cache_));
  char **cache = malloc(sSize * sizeof(*cache));
  for (int i = 0; i < sSize; ++i) {
    cache[i] = &cache_[pSize * i];
    for (int j = 0; j < pSize; ++j) {
      cache[i][j] = CACHE_UNKNOWN;
    }
  }

  bool res = dfs(s, p, 0, 0, cache);

  free(cache);
  free(cache_);
  return res;
}

int main(int argc, char *argv[]) {
  bool res_1 = isMatch("aa", "*");
  printf("res_1 = %s\n", res_1 ? "true" : "false");
  bool res_2 = isMatch("cb", "?a");
  printf("res_2 = %s\n", res_2 ? "true" : "false");
  bool res_3 = isMatch("acdcb", "a*c?b");
  printf("res_3 = %s\n", res_3 ? "true" : "false");
  bool res_4 = isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
  printf("res_4 = %s\n", res_4 ? "true" : "false");
  bool res_5 = isMatch(
      "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababba"
      "abbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
      "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
  printf("res_5 = %s\n", res_5 ? "true" : "false");
  return 0;
}
