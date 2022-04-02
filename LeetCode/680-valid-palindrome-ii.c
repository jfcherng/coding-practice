#include "_leetcode_common.c"

bool validPalindromeLR(char *s, int l, int r, int tolerance) {
  while (l < r) {
    if (s[l] != s[r]) {
      return tolerance > 0 ? (validPalindromeLR(s, l + 1, r, tolerance - 1) || // delete at `l`
                              validPalindromeLR(s, l, r - 1, tolerance - 1))   // delete at `r`
                           : false;
    }
    ++l;
    --r;
  }

  return true;
}

bool validPalindrome(char *s) {
  return validPalindromeLR(s, 0, strlen(s) - 1, 1);
}

int main(int argc, char *argv[]) {
  return 0;
}
