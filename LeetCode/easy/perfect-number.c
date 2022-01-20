#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool checkPerfectNumber(int num) {
  int sum = 0;
  for (int i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      sum += i;

      if (i * i != num) {
        sum += num / i;
      }
    }
  }

  return sum - num == num;
}

int main(int argc, char *argv[]) {
  printf("result: %d\n", checkPerfectNumber(28));

  return 0;
}
