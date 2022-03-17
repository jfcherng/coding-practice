#include "_leetcode_common.c"

// "(()(()))"
//  (1 (()))
//  (1 (1 ))
//  (1 2   )
//  (3     )
//  6

int scoreOfParentheses(char *s) {
  int len = strlen(s);

  int *stack = malloc((len + 1) * sizeof(*stack));
  int stackIdx = -1;
  stack[++stackIdx] = 0;

  for (int i = 0; i < len; ++i) {
    if (s[i] == '(') {
      stack[++stackIdx] = 0; // push
      continue;
    }

    // meet ")"
    int innerScore = stack[stackIdx] ? (stack[stackIdx] << 1) : 1;
    stack[--stackIdx] += innerScore; // pop
  }

  int score = stack[0];
  free(stack);
  return score;
}

int main(int argc, char *argv[]) {
  int res = -1;

  res = scoreOfParentheses("(()(()))");
  printf("res = %d\n", res);

  res = scoreOfParentheses("()()");
  printf("res = %d\n", res);

  return 0;
}
