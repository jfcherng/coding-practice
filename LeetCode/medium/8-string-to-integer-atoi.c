#include "uthash.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I32_MAX 0x7fffffff
#define I32_MIN 0x80000000

int myAtoi(char *s) {
  int sum = 0;
  int sign = 1;

  // skip leading spaces
  while (*s && *s == ' ') {
    s++;
  }

  // check sign
  if (*s == '+') {
    sign = 1;
    s++;
  } else if (*s == '-') {
    sign = -1;
    s++;
  }

  // printf("sign = '%c'\n", sign == 1 ? '+' : '-');

  // parse digits
  while ('0' <= *s && *s <= '9') {
    // printf("%c\n", *s);

    // positive overflow
    if (sign == 1 && sum >= (I32_MAX - (*s - '0')) / 10.0) {
      return (int) I32_MAX;
    }
    // negative overflow
    if (sign == -1 && sum > (I32_MAX - (*s - '0')) / 10.0) {
      return (int) I32_MIN;
    }

    sum = sum * 10 + (*s - '0');
    s++;
  }

  return sum * sign;
}

int main(int argc, char *argv[]) {
  printf("ans_1 = %d (42)\n", myAtoi("42"));
  printf("ans_1 = %d (-42)\n", myAtoi("   -42"));
  printf("ans_1 = %d (2147483646)\n", myAtoi("2147483646"));

  return 0;
}
