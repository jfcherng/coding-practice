#include "_leetcode_common.h"
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxProfit(int *prices, int pricesSize) {
  if (pricesSize <= 1) {
    return 0;
  }

  // dp[i] = the max value after i-th (excludesive)
  int *dp = malloc(pricesSize * sizeof(*dp));
  dp[pricesSize - 1] = -INT_MAX;
  for (int i = pricesSize - 2; i >= 0; --i) {
    dp[i] = MAX(dp[i + 1], prices[i + 1]);
  }

  int max_profit = 0;
  for (int i = 0; i < pricesSize - 1; ++i) {
    max_profit = MAX(max_profit, dp[i] - prices[i]);
  }
  return max_profit;
}

int main(int argc, char *argv[]) {
  return 0;
}
