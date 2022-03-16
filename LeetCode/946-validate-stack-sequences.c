#include "_leetcode_common.c"

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize) {
  int *stack = malloc(pushedSize * sizeof(*stack)), stackIdx = -1;
  int pushIdx = 0, popIdx = 0;

  while (popIdx != poppedSize) {
    // stack top item matches current popped, then we do pop
    if (stackIdx != -1 && stack[stackIdx] == popped[popIdx]) {
      ++popIdx, --stackIdx;
      continue;
    }

    // push new item onto stack
    if (pushIdx == pushedSize)
      return false;
    stack[++stackIdx] = pushed[pushIdx++];
  }

  return true;
}

int main(int argc, char *argv[]) {
  return 0;
}
