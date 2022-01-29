#include "_leetcode_common.h"

#define SEA ('0')
#define LAND ('1')
#define VISITED_LAND ('3')

void visitCell(char **grid, int m, int n, int r, int c) {
  if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != LAND) {
    return;
  }

  grid[r][c] = VISITED_LAND;

  visitCell(grid, m, n, r - 1, c);
  visitCell(grid, m, n, r + 1, c);
  visitCell(grid, m, n, r, c - 1);
  visitCell(grid, m, n, r, c + 1);
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
  int count = 0, m = gridSize, n = m ? gridColSize[0] : 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == LAND) {
        ++count;
        visitCell(grid, m, n, i, j);
      }
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  return 0;
}
