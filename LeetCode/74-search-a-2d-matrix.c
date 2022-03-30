#include "_leetcode_common.c"

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
  int colSize = matrixSize, rowSize = matrixColSize[0];
  int numsSize = rowSize * colSize;

  int l = 0, r = numsSize - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int pivot = matrix[mid / rowSize][mid % rowSize];

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
