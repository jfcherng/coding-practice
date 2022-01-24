#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s) {
  printf("input: %s\n", s);
  int len = strlen(s);

  // init DP table
  bool **is_palindromic = malloc(len * sizeof(*is_palindromic));
  bool *tmp = malloc(len * len * sizeof(*tmp));
  for (int i = 0; i < len; ++i) {
    is_palindromic[i] = &tmp[i * len];
  }

  // initial conditions
  for (int i = 0; i < len; ++i) {
    // single char
    is_palindromic[i][i] = true;
    // two neighbor chars
    if (i + 1 < len)
      is_palindromic[i][i + 1] = s[i] == s[i + 1];
  }

  // fill table
  for (int step = 2; step < len; ++step) {
    for (int l = 0; l < len; ++l) {
      int r = l + step;
      if (r >= len)
        continue;
      is_palindromic[l][r] = is_palindromic[l + 1][r - 1] && s[l] == s[r];
      printf("is_palindromic[%d][%d] = %d\n", l, r, is_palindromic[l][r]);
    }
  }

  // find max
  int res_l = 0, res_r = 0;
  for (int l = 0; l < len; ++l) {
    for (int r = l; r < len; ++r) {
      if (is_palindromic[l][r] && res_r - res_l < r - l) {
        res_l = l;
        res_r = r;
      }
    }
  }

  int res_len = res_r - res_l + 1;
  char *res = malloc((res_len + 1) * sizeof(*res));
  strncpy(res, s + res_l, res_len);
  res[res_len] = '\0';

  free(tmp);
  free(is_palindromic);

  return res;
}

int main(int argc, char *argv[]) {
  printf("ans(%s) = %s\n", "babad", longestPalindrome("babad"));
  return 0;
}
