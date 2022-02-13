#include "_leetcode_common.h"

char findTheDifference(char *s, char *t) {
  char k = 0;

  while (*s) {
    k ^= *s++;
  }
  while (*t) {
    k ^= *t++;
  }

  return k;
}

int main(int argc, char *argv[]) {
  return 0;
}
