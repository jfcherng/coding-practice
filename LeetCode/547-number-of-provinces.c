#include "_leetcode_common.c"

void explore(int **isConnected, bool *visited, int n, int node) {
  if (visited[node])
    return;

  visited[node] = true;
  for (int i = 0; i < n; ++i) {
    if (isConnected[i][node]) {
      explore(isConnected, visited, n, i);
    }
  }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize) {
  int n = isConnectedSize; // n x n matrix
  int res = 0;

  bool *visited = malloc(n * sizeof(*visited));
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      ++res;
      explore(isConnected, visited, n, i);
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
