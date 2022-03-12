#include "_leetcode_common.c"

// find nodes which have no incoming edge
int *findSmallestSetOfVertices(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize) {
  *returnSize = n;

  bool *hasIncoming = calloc(n, sizeof(*hasIncoming)); // `false` by default
  for (int i = 0; i < edgesSize; ++i) {
    int dst = edges[i][1];
    if (!hasIncoming[dst]) {
      hasIncoming[dst] = true;
      --*returnSize;
    }
  }

  int *res = malloc(*returnSize * sizeof(*res)), resIdx = -1;
  for (int i = 0; i < n; ++i) {
    if (!hasIncoming[i]) {
      res[++resIdx] = i;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
