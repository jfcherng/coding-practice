#include "_leetcode_common.c"

#define ARR_SIZE (128)

int longestPalindrome(char *s) {
  int *cnt = calloc(128, sizeof(*cnt));
  int res = 0,
      rest = 0; // unmatched count (can still be used as the mid char in a palindrome)

  // build cnt
  while (*s) {
    ++cnt[*s++];
  }

  // count pair-able chars for res
  for (int i = 0; i < ARR_SIZE; ++i) {
    res += cnt[i] & ~1; // the largest even number <= cnt[i]
    rest += cnt[i] & 1; // remainder after being divided by 2
  }

  if (rest) {
    ++res;
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
