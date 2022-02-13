#include "_leetcode_common.h"

#define NEGATIVE_MIN 0x80000000
#define POSITIVE_MAX 0x7fffffff

int reverse(int x) {
  if (x == NEGATIVE_MIN)
    return 0;

  // printf("=== Process %d ===\n", x);

  int sign = (x >> 31) & 1;

  int digits[32] = {0};
  int digit_cnt = 0;

  // printf("sign = %d\n", sign);

  x *= sign ? -1 : 1;
  while (x) {
    digits[digit_cnt++] = x % 10;
    x /= 10;
  }

  int reversed = 0;
  for (int i = 0; i < digit_cnt; ++i) {
    // overflow
    if (reversed >= (POSITIVE_MAX - digits[i]) / 10.0) {
      return 0;
    }

    reversed = reversed * 10 + digits[i];
  }

  // printf("reversed = %d\n", reversed);

  return reversed * (sign ? -1 : 1);
}

int main(int argc, char *argv[]) {
  int input;

  input = 123;
  printf("reverse(%d) = %d\n", input, reverse(input));
  input = -123;
  printf("reverse(%d) = %d\n", input, reverse(input));
  input = 120;
  printf("reverse(%d) = %d\n", input, reverse(input));

  return 0;
}
