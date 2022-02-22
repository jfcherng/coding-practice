#include "_leetcode_common.c"

bool isBadVersion(int n);

int firstBadVersion(int n) {
  int res = INT_MAX, l = 1, r = n;

  while (l <= r) {
    int m = l + (r - l) / 2; // overflow

    if (isBadVersion(m)) {
      res = m; // since bad version found by decreasing, no need for MIN()
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
