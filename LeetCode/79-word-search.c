#include "_leetcode_common.c"

const int directions[] = {1, 0, -1, 0, 1};

bool bt(char **board, int m, int n, int r, int c, char *word) {
  if (!*word)
    return true;

  if (r < 0 || r == m || c < 0 || c == n || board[r][c] != *word)
    return false;

  board[r][c] *= -1; // pick
  for (int i = 0; i < 4; ++i) {
    if (bt(board, m, n, r + directions[i], c + directions[i + 1], word + 1))
      return true;
  }
  board[r][c] *= -1; // restore pick

  return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
  int m = boardSize, n = m ? boardColSize[0] : 0;

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (bt(board, m, n, r, c, word))
        return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  return 0;
}
