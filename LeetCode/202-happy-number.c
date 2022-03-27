#include "_leetcode_common.c"

int getNext(int n) {
  int sum = 0;
  while (n) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  int slow = n, fast = getNext(n);

  while (fast != 1 && slow != fast) {
    slow = getNext(slow);
    fast = getNext(getNext(fast));
  }

  return fast == 1;
}

int main(int argc, char *argv[]) {
  printf("res = %s (true)\n", isHappy(10) ? "true" : "false");
  printf("res = %s (true)\n", isHappy(19) ? "true" : "false");
  printf("res = %s (false)\n", isHappy(2) ? "true" : "false");

  return 0;
}
