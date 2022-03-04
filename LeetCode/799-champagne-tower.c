#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define SWAP_PTR(x, y)                                                                                                 \
  {                                                                                                                    \
    void *tmp = x;                                                                                                     \
    x = y;                                                                                                             \
    y = tmp;                                                                                                           \
  }

double champagneTower(int poured, int row, int col) {
  double res = 0.0;

  // the "flux" of glasses of a row
  double *curr = malloc((row + 1) * sizeof(double)), *next = malloc((row + 1) * sizeof(double));
  bool pour_next_row = true;

  curr[0] = poured; // the 0th row
  for (int r = 0; r <= row; ++r) {
    // fast return
    if (!pour_next_row) {
      break;
    }

    if (r == row) {
      res = curr[col];
      break;
    }

    // init next
    memset(next, 0, (r + 2) * sizeof(double));

    pour_next_row = false;
    for (int c = 0; c <= r; ++c) {
      double excessiveSplit = (curr[c] - 1.0) / 2.0;
      if (excessiveSplit > 0.0) {
        pour_next_row = true;
        next[c] += excessiveSplit;     // the left glass in the next row
        next[c + 1] += excessiveSplit; // the right glass in the next row
      }
    }

    SWAP_PTR(curr, next);
  }

  free(curr);
  free(next);

  return MIN(res, 1.0);
}

int main(int argc, char *argv[]) {
  double res = champagneTower(2, 1, 1);
  printf("res = %lf\n", res);

  return 0;
}
