#include "_leetcode_common.c"

// "(   ()    (   ()  )  )"
//  2(  1  +  2(  1   )  ) = score
//  We calculate the final score as above.
//  When we meet 1, we can calculate its score with the current "depth".
int scoreOfParentheses(char *s) {
  int score = 0, depth = -1;
  // (())()
  for (; *s; ++s) {
    if (*s == '(') {
      ++depth;
      continue;
    }

    // meet ')'
    if (*(s - 1) == '(')
      score += 1 << depth;
    --depth;
  }

  return score;
}

// "(()(()))"
//  (1 (()))
//  (1 (1 ))
//  (1 2   )
//  (3     )
//  6
int scoreOfParentheses_stack(char *s) {
  int len = strlen(s);

  int *stack = malloc(((len >> 1) + 1) * sizeof(*stack));
  int stackIdx = -1;
  stack[++stackIdx] = 0; // our final score

  for (int i = 0; i < len; ++i) {
    if (s[i] == '(') {
      stack[++stackIdx] = 0; // push
      continue;
    }

    // meet ")"
    // int innerScore = stack[stackIdx] ? (stack[stackIdx] << 1) : 1;
    // stack[--stackIdx] += innerScore; // pop

    // optimized code for the above
    stack[stackIdx - 1] += (stack[stackIdx] == 0) + (stack[stackIdx] << 1);
    --stackIdx; // pop
  }

  int score = stack[0];
  free(stack);
  return score;
}

int main(int argc, char *argv[]) {
  int res = -1;

  res = scoreOfParentheses("(())()");
  printf("res = %d\n", res);

  res = scoreOfParentheses("(()(()))");
  printf("res = %d\n", res);

  res = scoreOfParentheses("()()");
  printf("res = %d\n", res);

  return 0;
}
