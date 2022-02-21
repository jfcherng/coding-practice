#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
  int *data;
  int size;
  int capacity;
} vector;

vector *vectorCreate(int capacity) {
  vector *v = malloc(sizeof(*v));
  v->capacity = MAX(1, capacity);
  v->size = 0;
  v->data = malloc(sizeof(*(v->data)) * v->capacity);
  return v;
}

void vectorDestroy(vector *v) {
  free(v->data);
  free(v);
  v = NULL;
}

void vectorPushback(vector *v, int val) {
  if (v->size == v->capacity) {
    v->capacity = MAX(1, v->capacity) * 2;
    v->data = realloc(v->data, sizeof(*(v->data)) * v->capacity);
  }
  v->data[v->size++] = val;
}

int vectorPopback(vector *v) {
  return v->data[v->size--];
}

int vectorAt(vector *v, int idx) {
  return v->data[idx];
}

void vectorPrint(vector *v) {
  if (v->size) {
    printf("%d", v->data[0]);
    for (int i = 1; i < v->size; ++i) {
      printf(" -> %d", v->data[i]);
    }
  }
  printf("\n");
}

int numSquares(int n) {
  // BFS (level-ordering traversal)
  int level = 0;

  int squaresLen = (int) sqrt(n);
  int *squares = malloc(sizeof(*squares) * squaresLen); // 1, 4, 9, ...
  for (int i = 1; i <= squaresLen; ++i) {
    squares[i - 1] = i * i;
  }

  vector *v = vectorCreate(n);
  vectorPushback(v, n);

  while (v->size) {
    ++level;
    vector *vNext = vectorCreate(n);

    for (int i = 0; i < v->size; ++i) {
      for (int j = 0; j < squaresLen; ++j) {
        int diff = vectorAt(v, i) - squares[j];
        if (diff == 0)
          return level;
        if (diff < 0)
          break;
        vectorPushback(vNext, diff);
      }
    }

    vectorDestroy(v);
    v = vNext;
  }

  // something goes wrong
  return -1;
}

int numSquares_dp(int n) {
  int *dp = malloc((n + 1) * sizeof(*dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = INT_MAX;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      dp[i] = MIN(dp[i], 1 + dp[i - j * j]);
    }
  }

  return dp[n];
}

int main(int argc, char *argv[]) {

  int res = numSquares(15);
  printf("res = %d\n", res);

  return 0;
}
