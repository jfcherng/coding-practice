#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define BIG_NUMBER (INT_MAX >> 1)

int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes) {
  // get matrix sizes
  int m = matSize, n = matColSize[0];

  // set return sizes
  *returnSize = m;
  *returnColumnSizes = malloc(m * sizeof(**returnColumnSizes));
  for (int r = 0; r < m; ++r)
    (*returnColumnSizes)[r] = n;

  // init return matrix (res)
  int *cells = calloc(m * n, sizeof(*cells));
  int **res = malloc(m * sizeof(*res));
  for (int r = 0; r < m; ++r)
    res[r] = &cells[n * r];

  // scan top-left
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (mat[r][c]) {
        int top = r > 0 ? res[r - 1][c] : BIG_NUMBER;
        int left = c > 0 ? res[r][c - 1] : BIG_NUMBER;
        res[r][c] = MIN(top, left) + 1;
      }
    }
  }

  // scan bottom-right
  for (int r = m - 1; r >= 0; --r) {
    for (int c = n - 1; c >= 0; --c) {
      if (mat[r][c]) {
        int bottom = r < m - 1 ? res[r + 1][c] : BIG_NUMBER;
        int right = c < n - 1 ? res[r][c + 1] : BIG_NUMBER;
        res[r][c] = MIN(res[r][c], MIN(bottom, right) + 1);
      }
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
