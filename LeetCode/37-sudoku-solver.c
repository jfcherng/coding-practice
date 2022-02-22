#include "_leetcode_common.c"

void prepareCandidates(char **board, int r, int c, bool *used) {
  int top = r - (r % 3), left = c - (c % 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int k = 3 * i + j;
      if (board[r][k] != '.')
        used[board[r][k] - '0'] = true;
      if (board[k][c] != '.')
        used[board[k][c] - '0'] = true;
      if (board[top + i][left + j] != '.')
        used[board[top + i][left + j] - '0'] = true;
    }
  }
}

bool bt(char **board, int n) {
  if (n == 81)
    return true;

  int r = n / 9, c = n % 9;
  if (board[r][c] != '.')
    return bt(board, n + 1);

  bool used[10] = {}; // default 0 (false)
  prepareCandidates(board, r, c, used);
  for (int i = 1; i < 10; ++i) {
    if (used[i])
      continue;
    board[r][c] = '0' + i;
    if (bt(board, n + 1))
      return true;
    board[r][c] = '.';
  }

  return false;
}

void solveSudoku(char **board, int boardSize, int *boardColSize) {
  bt(board, 0);
}

int main(int argc, char *argv[]) {
  return 0;
}
