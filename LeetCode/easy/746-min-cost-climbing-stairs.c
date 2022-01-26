#include "_leetcode_common.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCostClimbingStairs(int *cost, int costSize) {
  if (costSize < 2) {
    return cost[costSize];
  }

  // the min cost to leave i-th floor
  int *dp = malloc((costSize + 2) * sizeof(*dp));
  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < costSize; ++i) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
  }

  return min(dp[costSize - 1], dp[costSize - 2]);
}

int main(int argc, char *argv[]) {
  int costs1[] = {10, 15, 20};
  int *costs1p = &costs1[0];
  printf("%d\n", minCostClimbingStairs(costs1p, 3));
  return 0;
}
