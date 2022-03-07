#include "_leetcode_common.c"

// time complexity: O(D), space complexity: O(1)
uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i = 0; i < 32; ++i) {
    res |= ((n >> i) & 1) << (31 - i);
  }
  return res;
}

// time complexity: O(log(D)), space complexity: O(1)
uint32_t reverseBits_log_complexity(uint32_t n) {
  uint32_t s = 8 * sizeof(n), mask = ~0;
  while (s >>= 1) {
    mask ^= mask << s;
    n = ((n >> s) & mask) | ((n << s) & ~mask);
  }
  return n;
}

int main(int argc, char *argv[]) {
  return 0;
}
