#include "_leetcode_common.c"

typedef struct {
  char c;  // '(' or ')'
  int idx; // the index in the source string
} StackItem;

char *minRemoveToMakeValid(char *s) {
  int len = strlen(s);
  char *res = calloc(len + 1, sizeof(*res));
  int resIdx = -1;

  // parentheses stack
  StackItem *stack = calloc(len + 1, sizeof(*stack));
  int stackIdx = -1;

  // constrcut stack
  for (int i = 0; i < len; ++i) {
    if (s[i] == '(') {
      stack[++stackIdx] = (StackItem){.c = s[i], .idx = i};
    } else if (s[i] == ')') {
      // cancelled out
      if (stackIdx >= 0 && stack[stackIdx].c == '(') {
        --stackIdx;
      } else {
        stack[++stackIdx] = (StackItem){.c = s[i], .idx = i};
      }
    }
  }

  for (int i = 0, p = 0; i < len; ++i) {
    if (p <= stackIdx && stack[p].idx == i) {
      ++p;
      continue;
    }
    res[++resIdx] = s[i];
  }

  free(stack);
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
