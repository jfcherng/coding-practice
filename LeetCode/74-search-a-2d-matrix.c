#include "_leetcode_common.h"

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
  int colSize = matrixSize, rowSize = matrixColSize[0];
  int numsSize = rowSize * colSize;

  int l = 0, r = numsSize - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    int mid_row = mid / rowSize;
    int mid_col = mid % rowSize;
    int pivot = matrix[mid_row][mid_col];

    if (pivot < target) {
      l = mid + 1;
    } else if (pivot > target) {
      r = mid - 1;
    } else {
      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  return 0;
}
