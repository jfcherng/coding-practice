#include "_leetcode_common.c"

bool backspaceCompare(char *s, char *t) {
  // compare strings in reversed order, "#" means we can skip the next char
  int sIdx = strlen(s) - 1, tIdx = strlen(t) - 1;
  int sCanSkip = 0, tCanSkip = 0;

  while (sIdx >= 0 || tIdx >= 0) {
    // move sIdx to the next comparable char in s
    while (sIdx >= 0) {
      if (s[sIdx] == '#') {
        ++sCanSkip;
      } else if (sCanSkip > 0) {
        --sCanSkip;
      } else {
        break;
      }
      --sIdx;
    }
    // move tIdx to the next comparable char in t
    while (tIdx >= 0) {
      if (t[tIdx] == '#') {
        ++tCanSkip;
      } else if (tCanSkip > 0) {
        --tCanSkip;
      } else {
        break;
      }
      --tIdx;
    }
    // compare
    if ((sIdx < 0) ^ (tIdx < 0)) {
      return false;
    }
    if (sIdx >= 0 && tIdx >= 0 && s[sIdx] != t[tIdx]) {
      return false;
    }
    // next iteration
    --sIdx;
    --tIdx;
  }

  return sIdx < 0 && tIdx < 0;
}

int main(int argc, char *argv[]) {
  return 0;
}
