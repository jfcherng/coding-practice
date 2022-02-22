#include "_leetcode_common.c"

#define assertCell(board, set, m, n)                                                                                   \
  {                                                                                                                    \
    if (board[m][n] == '.')                                                                                            \
      continue;                                                                                                        \
    if (set[board[m][n] - '0'])                                                                                        \
      return false;                                                                                                    \
    set[board[m][n] - '0'] = true;                                                                                     \
  }

bool isValidRow(char **board, bool *set, int n) {
  memset(set, false, 10 * sizeof(*set));
  for (int i = 0; i < 9; ++i)
    assertCell(board, set, n, i);
  return true;
}

bool isValidCol(char **board, bool *set, int n) {
  memset(set, false, 10 * sizeof(*set));
  for (int i = 0; i < 9; ++i)
    assertCell(board, set, i, n);
  return true;
}

bool isValidBlk(char **board, bool *set, int i, int j) {
  memset(set, false, 10 * sizeof(*set));
  for (int m = 0; m < 3; ++m)
    for (int n = 0; n < 3; ++n)
      assertCell(board, set, i + m, j + n);
  return true;
}

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
  bool set[10] = {};

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if (!isValidRow(board, set, i + 3 * j) || //
          !isValidCol(board, set, 3 * i + j) || //
          !isValidBlk(board, set, 3 * i, 3 * j))
        return false;
    }

  return true;
}

int main(int argc, char *argv[]) {
  char board_1_[][9] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, //
                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, //
                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, //
                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, //
                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, //
                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, //
                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, //
                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, //
                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  char *board_1[] = {
      board_1_[0], board_1_[1], board_1_[2], //
      board_1_[3], board_1_[4], board_1_[5], //
      board_1_[6], board_1_[7], board_1_[8], //
  };

  bool res = isValidSudoku(board_1, 0, NULL);
  printf("res = %s\n", res ? "true" : "false");

  return 0;
}
