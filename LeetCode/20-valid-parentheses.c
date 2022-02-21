#include "_leetcode_common.c"

const int PAIRS_CNT = 3;
const char *PAIRS[] = {"()", "[]", "{}"};

bool isValid(char *s) {
  int top = -1; // use "s" as in-place stack

  for (int i = 0; s[i]; ++i) {
    bool isOpening = true;
    for (int j = 0; j < PAIRS_CNT; ++j) {
      // is closing bracket?
      if (s[i] == PAIRS[j][1]) {
        isOpening = false;
        // pair unmatched
        if (top == -1 || s[top] != PAIRS[j][0])
          return false;
        // pair matched
        --top;
        break;
      }
    }

    if (isOpening)
      s[++top] = s[i];
  }

  return top == -1; // empty stack
}

int main(int argc, char *argv[]) {
  return 0;
}
