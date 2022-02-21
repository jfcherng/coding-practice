#include "_leetcode_common.c"

int sorter(const void *r1, const void *r2) {
  int *_r1 = *(int **) r1, *_r2 = *(int **) r2;
  return _r1[0] != _r2[0] ? _r1[0] - _r2[0] : _r2[1] - _r1[1];
}

/**
 * Determines whether a covers b.
 */
static inline bool is_covered(int *r1, int *r2) {
  return r1[0] <= r2[0] && r2[1] <= r1[1];
}

int removeCoveredIntervals(int **intervals, int intervalsSize, int *intervalsColSize) {
  if (intervalsSize == 0)
    return 0;

  qsort(intervals, intervalsSize, 2 * sizeof(int), sorter);

  int res = intervalsSize;
  int *prev = intervals[0];
  for (int i = 1; i < intervalsSize; ++i) {
    if (is_covered(prev, intervals[i])) {
      --res;
    } else {
      prev = intervals[i];
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
