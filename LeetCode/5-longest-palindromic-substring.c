#include "_leetcode_common.c"

char *longestPalindrome(char *s) {
  int len = strlen(s);

  // init DP table
  // is_palindromic[i][j] = s[i..j] is palindromic or not
  bool **is_palindromic = malloc(len * sizeof(*is_palindromic));
  bool *tmp = malloc(len * len * sizeof(*tmp));
  for (int i = 0; i < len; ++i)
    is_palindromic[i] = tmp + i * len;

  // trivial initial conditions
  for (int i = 0; i < len; ++i) {
    // length=1 substring is palindromic
    is_palindromic[i][i] = true;
    // length=2 substring is palindromic if they are the same
    if (i + 1 < len)
      is_palindromic[i][i + 1] = s[i] == s[i + 1];
  }

  // fill table
  for (int length = 3; length <= len; ++length) {
    for (int l = 0; l <= len - length; ++l) {
      int r = l + (length - 1);
      is_palindromic[l][r] = is_palindromic[l + 1][r - 1] && s[l] == s[r];
      // printf("is_palindromic[%d][%d] = %d\n", l, r, is_palindromic[l][r]);
    }
  }

  // find max length
  int res_l = 0, res_len = 1;
  for (int l = 0; l <= len - res_len; ++l) {
    for (int r = l + res_len; r < len; ++r) {
      if (is_palindromic[l][r] && res_len < r - l + 1) {
        res_l = l;
        res_len = r - l + 1;
      }
    }
  }

  char *res = calloc(res_len + 1, sizeof(*res));
  strncpy(res, s + res_l, res_len);

  free(tmp);
  free(is_palindromic);

  return res;
}

int main(int argc, char *argv[]) {
  printf("longestPalindrome(%s) = %s\n", "babad", longestPalindrome("babad"));
  return 0;
}
