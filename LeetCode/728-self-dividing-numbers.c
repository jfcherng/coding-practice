#include "_leetcode_common.c"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *selfDividingNumbers(int left, int right, int *returnSize) {
  int array_size = 32;
  int *results = (int *) malloc(array_size * sizeof(int));

  *returnSize = 0;
  for (int i = left; i <= right; ++i) {
    int j = i;
    while (j) {
      int digit = j % 10;
      if (digit == 0 || i % digit != 0) {
        break;
      }
      j /= 10;
    }

    // found
    if (i != 0 && j == 0) {
      results[(*returnSize)++] = i;

      // make array bigger
      if (*returnSize >= array_size) {
        results = (int *) realloc(results, (array_size <<= 1) * sizeof(int));
      }
    }
  }

  return results;
}

void printResults(int left, int right) {
  int *size = (int *) malloc(sizeof(int));
  int *results = selfDividingNumbers(left, right, size);

  for (int i = 0; i < *size; ++i) {
    printf("%d, ", results[i]);
  }
  printf("\n\n");

  free(results);
  free(size);
}

int main(int argc, char *argv[]) {
  printResults(1, 22);
  printResults(66, 708);

  return 0;
}
