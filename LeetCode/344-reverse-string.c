#include "_leetcode_common.c"

void reverseString(char *s, int sSize) {
  char tmp;
  for (int i = 0; i < sSize / 2; ++i) {
    tmp = s[i];
    s[i] = s[sSize - 1 - i];
    s[sSize - 1 - i] = tmp;
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
