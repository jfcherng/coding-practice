#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int coinChange(int *coins, int coinsSize, int amount) {
  int *dp = malloc((amount + 1) * sizeof(*dp));

  // initial conditions
  dp[0] = 0;
  for (int i = 1; i <= amount; ++i)
    dp[i] = INT_MAX;
  for (int i = 0; i < coinsSize; ++i)
    if (coins[i] <= amount)
      dp[coins[i]] = 1;

  for (int i = 1; i <= amount; ++i) {
    if (dp[i] != INT_MAX)
      continue;
    for (int j = 0; j < coinsSize; ++j) {
      int rest = i - coins[j]; // try take coins[j]
      if (rest >= 0)
        dp[i] = MIN(dp[i], 1 + dp[rest]);
    }
  }

  int res = dp[amount];
  free(dp);
  return res == INT_MAX ? -1 : res;
}

int main(int argc, char *argv[]) {
  int res;

  int coins_1[] = {1, 2, 5};
  res = coinChange(coins_1, sizeof(coins_1) / sizeof(int), 11);
  printf("res = %d (3)\n", res);

  int coins_2[] = {1};
  res = coinChange(coins_2, sizeof(coins_2) / sizeof(int), 0);
  printf("res = %d (-1)\n", res);

  return 0;
}
