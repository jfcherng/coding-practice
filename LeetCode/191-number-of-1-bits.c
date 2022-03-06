#include "_leetcode_common.c"

int hammingWeight(uint32_t n) {
  int res = 0;
  while (n) {
    n &= n - 1;
    ++res;
  }
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
