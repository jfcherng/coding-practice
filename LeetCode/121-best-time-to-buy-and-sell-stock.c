#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxProfit(int *prices, int pricesSize) {
  int max_profit = 0;

  int buyAt = prices[0];
  for (int i = 1; i < pricesSize; ++i) {
    int profit = prices[i] - buyAt;

    if (profit < 0) {
      buyAt = prices[i];
    } else if (profit > max_profit) {
      max_profit = profit;
    }
  }

  return max_profit;
}

int maxProfit_dp(int *prices, int pricesSize) {
  // dp[i] = the max value after i-th (excludesive)
  int *dp = malloc(pricesSize * sizeof(*dp));
  dp[pricesSize - 1] = -INT_MAX;
  for (int i = pricesSize - 2; i >= 0; --i)
    dp[i] = MAX(dp[i + 1], prices[i + 1]);

  int max_profit = 0;
  for (int i = 0; i < pricesSize - 1; ++i)
    max_profit = MAX(max_profit, dp[i] - prices[i]);
  return max_profit;
}

int main(int argc, char *argv[]) {
  return 0;
}
