#include "_leetcode_common.h"

bool isPalindrome(int x) {
  if (x < 0)
    return false;

  int digits[32];
  int digit_cnt = 0;
  while (x) {
    digits[digit_cnt++] = x % 10;
    x /= 10;
  }

  for (int i = 0; i < digit_cnt / 2; ++i) {
    if (digits[i] != digits[digit_cnt - 1 - i])
      return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  int input;

  input = 121;
  printf("isPalindrome(%d) = %d\n", input, isPalindrome(input));
  input = -121;
  printf("isPalindrome(%d) = %d\n", input, isPalindrome(input));
  input = 10;
  printf("isPalindrome(%d) = %d\n", input, isPalindrome(input));

  return 0;
}
