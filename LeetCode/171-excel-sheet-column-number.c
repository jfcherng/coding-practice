#include "_leetcode_common.c"

int titleToNumber(char *columnTitle) {
  int res = 0;

  unsigned int weighting = 1;
  for (int i = strlen(columnTitle) - 1; i >= 0; --i) {
    res += (columnTitle[i] - 'A' + 1) * weighting;
    weighting *= 26;
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
