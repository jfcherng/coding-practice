#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
  if (numRows == 1) {
    return s;
  }

  int sSize = strlen(s);

  char *ret = malloc(1001 * sizeof(char));
  int retSize = 0; // exlucde \0

  int *rowSizes = malloc(numRows * sizeof(*rowSizes));
  char **rows = malloc(numRows * sizeof(*rows));
  for (int i = 0; i < numRows; ++i) {
    rows[i] = malloc((sSize + 1) * sizeof(char)); // naive
    rowSizes[i] = 0;
  }

  int current_row = 0;
  int row_direction = 1;
  for (int i = 0; i < sSize; ++i) {
    rows[current_row][rowSizes[current_row]] = s[i];
    ++rowSizes[current_row];
    current_row += row_direction;

    if (current_row == 0 || current_row == numRows - 1) {
      row_direction *= -1;
    }
  }

  for (int i = 0; i < numRows; ++i) {
    rows[i][rowSizes[i]] = '\0';
    memcpy(ret + retSize, rows[i], rowSizes[i] * sizeof(char));
    retSize += rowSizes[i];
  }

  ret[retSize] = '\0';

  return ret;
}

int main(int argc, char *argv[]) {
  int numRows;
  char *s;

  s = "PAYPALISHIRING";
  numRows = 3;
  printf("=> convert(%s) = %s\n", s, convert(s, numRows));

  s = "PAYPALISHIRING";
  numRows = 4;
  printf("=> convert(%s) = %s\n", s, convert(s, numRows));

  s = "A";
  numRows = 1;
  printf("=> convert(%s) = %s\n", s, convert(s, numRows));

  s = "A";
  numRows = 2;
  printf("=> convert(%s) = %s\n", s, convert(s, numRows));

  return 0;
}
