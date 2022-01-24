#include "_leetcode_common.h"

double myPow(double x, int n) {
  double sum = 1.0;

  int sign = n < 0 ? -1 : 1;
  unsigned int nn = (unsigned int) n * sign; // let "nn" = positive "n"

  while (nn) {
    if (nn & 1) {
      sum *= x;
    }
    nn >>= 1;
    x *= x;
  }

  return sign == 1 ? sum : 1.0 / sum;
}

int main(int argc, char *argv[]) {
  printf("ans_1 = %f (1024.0)\n", myPow(2.0, 10));
  printf("ans_1 = %f (0.25)\n", myPow(2.0, -2));
  printf("ans_1 = %f (1.0)\n", myPow(1.0, -2147483648));

  return 0;
}
