#include "_leetcode_common.h"

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
  int res = -INT_MAX;

  for (int i = 0; i < accountsSize; ++i) {
    int sum = 0;
    for (int j = 0; j < accountsColSize[i]; ++j) {
      sum += accounts[i][j];
    }
    if (sum > res) {
      res = sum;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
