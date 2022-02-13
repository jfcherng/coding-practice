#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int longestValidParentheses(char *s) {
  int res = 0;

  int len = strlen(s);
  int *stack = malloc((len + 1) * sizeof(*stack));
  int idx = -1; // stack top idx

  stack[++idx] = -1; // push

  for (int i = 0; i < len; ++i) {
    int top = stack[idx];
    // matched
    if (top != -1 && s[top] == '(' && s[i] == ')') {
      --idx; // pop
      res = MAX(res, i - stack[idx]);
    }
    // unmatched
    else {
      stack[++idx] = i; // push
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  int res = longestValidParentheses("(()");

  printf("%d\n", res);

  return 0;
}
