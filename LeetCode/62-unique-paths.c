#include "_leetcode_common.c"

// time complexity = O(mn), space complexity = O(min(m, n))
int uniquePaths(int m, int n) {
  // let m >= n
  if (n > m)
    return uniquePaths(n, m);

  int *dp = malloc(n * sizeof(*dp));
  for (int c = 0; c < n; ++c)
    dp[c] = 1; // cols for the top row

  for (int r = 1; r < m; ++r)
    for (int c = 1; c < n; ++c)
      dp[c] += dp[c - 1];

  return dp[n - 1];
}

int main(int argc, char *argv[]) {
  printf("res = %d (28)\n", uniquePaths(3, 7));
  return 0;
}
