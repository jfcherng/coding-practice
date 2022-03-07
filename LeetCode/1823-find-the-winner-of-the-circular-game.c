#include "_leetcode_common.c"

int findTheWinner(int n, int k) {
  int res = 0;
  // bottom-up solution, assuming 0-index
  for (int i = 1; i < n; ++i) {
    res = (res + k) % (i + 1); // previous round has (i+1) person
  }
  return res + 1; // the original problem is 1-index
}

int main(int argc, char *argv[]) {
  return 0;
}
