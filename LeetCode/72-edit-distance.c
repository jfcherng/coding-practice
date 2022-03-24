#include "_leetcode_common.c"

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

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

int minDistance(char *s1, char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);

  // dp[i][j] = the min edit distance for s1[0..i) and s2[0..j)
  int **dp = malloc((l1 + 1) * sizeof(*dp));
  int *tmp = malloc((l1 + 1) * (l2 + 1) * sizeof(*tmp));
  for (int i = 0; i <= l1; ++i)
    dp[i] = tmp + i * (l2 + 1);

  // initial conditions
  for (int i = 0; i <= l1; ++i)
    dp[i][0] = i;
  for (int j = 0; j <= l2; ++j)
    dp[0][j] = j;

  // fill the rest of the table
  for (int i = 1; i <= l1; ++i) {
    for (int j = 1; j <= l2; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // dp[i][j] as a temp variable, we want to do dp[i][j] = 1 + min(...)
        dp[i][j] = MIN(dp[i - 1][j],                // delete
                       dp[i][j - 1]);               // insert
        dp[i][j] = MIN(dp[i][j], dp[i - 1][j - 1]); // replace
        ++dp[i][j];
      }
    }
  }

#ifdef DEBUG
  printDpTable(dp, s1, s2, l1, l2);
#endif

  int res = dp[l1][l2];
  free(tmp);
  free(dp);
  return res;
}

int main(int argc, char *argv[]) {
  printf("res = %d (3)\n\n\n", minDistance("horse", "ros"));
  printf("res = %d (5)\n\n\n", minDistance("intention", "execution"));
  return 0;
}
