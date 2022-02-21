#include "_leetcode_common.c"

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
  int m = matrixSize, n = m ? matrixColSize[0] : 0;

  // from the top-right corner,
  // if target > value, then row++
  //           <             column--
  //           =             BINGO!

  int r = 0, c = n - 1;
  while (r < m && c >= 0) {
    if (matrix[r][c] > target) {
      --c;
    } else if (matrix[r][c] < target) {
      ++r;
    } else {
      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  return 0;
}
