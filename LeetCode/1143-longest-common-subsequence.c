#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

void printDpTable(int **dp, char *s1, char *s2, int l1, int l2) {
  printf("========== DP Table ==========\n");
  printf("%4c%4c", ' ', '#');
  for (int j = 0; j <= l2; ++j) {
    printf("%4c", s2[j]);
  }
  printf("\n");
  for (int i = 0; i <= l1; ++i) {
    printf("%4c", i ? s1[i - 1] : '#');
    for (int j = 0; j <= l2; ++j) {
      printf("%4d", dp[i][j]);
    }
    printf("\n");
  }
}

int longestCommonSubsequence(char *s1, char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);

  // dp[i][j] = the min delete operation for s1[0..i) and s2[0..j)
  int **dp = malloc((l1 + 1) * sizeof(*dp));
  int *tmp = malloc((l1 + 1) * (l2 + 1) * sizeof(*tmp));
  for (int i = 0; i <= l1; ++i)
    dp[i] = tmp + i * (l2 + 1);

  // initial conditions
  for (int i = 0; i <= l1; ++i)
    dp[i][0] = 0;
  for (int j = 0; j <= l2; ++j)
    dp[0][j] = 0;

  for (int i = 1; i <= l1; ++i) {
    for (int j = 1; j <= l2; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

#ifdef DEBUG
  printDpTable(dp, s1, s2, l1, l2);
#endif

  int res = dp[l1][l2];
  free(dp);
  free(tmp);
  return res;
}

int main(int argc, char *argv[]) {
  printf("res = %d\n", longestCommonSubsequence("abcde", "ace"));

  return 0;
}
