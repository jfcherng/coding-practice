#include "_leetcode_common.c"

bool isPowerOfTwo(int n) {
  return n > 0 && (n & (n - 1)) == 0;
}

int main(int argc, char *argv[]) {
  return 0;
}
