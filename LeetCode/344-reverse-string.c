#include "_leetcode_common.c"

void reverseString(char *s, int sSize) {
  for (int i = (sSize >> 1) - 1; i >= 0; --i) {
    // swap index `i` and index `sSize-1-i`
    s[i] ^= s[sSize - 1 - i];
    s[sSize - 1 - i] ^= s[i];
    s[i] ^= s[sSize - 1 - i];
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
