#include "_leetcode_common.h"

int addDigits(int num) {
  if (num <= 9) {
    return num;
  }

  int sum = 0;

  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return addDigits(sum);
}

int main(int argc, char *argv[]) {
  return 0;
}
