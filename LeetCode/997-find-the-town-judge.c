#include "_leetcode_common.c"

int findJudge(int n, int **trust, int trustSize, int *trustColSize) {
  int *trustedMinusTrust = calloc(n + 1, sizeof(*trustedMinusTrust));

  for (int i = 0; i < trustSize; ++i) {
    --trustedMinusTrust[trust[i][0]];
    ++trustedMinusTrust[trust[i][1]];
  }

  for (int i = 1; i <= n; ++i) {
    if (trustedMinusTrust[i] == n - 1) {
      return i;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  return 0;
}
