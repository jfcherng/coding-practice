#include "_leetcode_common.c"

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int maxNumberOfBalloons(char *text) {
  // "balloon" = a1, b1, l2, n1, o1
  int res = 0;

  int a_cnt, b_cnt, l_cnt, n_cnt, o_cnt;
  a_cnt = b_cnt = l_cnt = n_cnt = o_cnt = 0;

  while (*text) {
    switch (*text) {
    case 'a':
      a_cnt++;
      break;
    case 'b':
      b_cnt++;
      break;
    case 'l':
      l_cnt++;
      break;
    case 'n':
      n_cnt++;
      break;
    case 'o':
      o_cnt++;
      break;
    }
    ++text;
  }

  return MIN(MIN(MIN(MIN(a_cnt, b_cnt), l_cnt / 2), n_cnt), o_cnt / 2);
}

int main(int argc, char *argv[]) {
  return 0;
}
