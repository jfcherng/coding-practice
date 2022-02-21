#include "_leetcode_common.c"

#define LOWER (1 << 0)
#define UPPER (1 << 1)

bool detectCapitalUse(char *word) {
  int allowed_state = LOWER | UPPER;

  for (int idx = 0; word[idx]; ++idx) {
    int type = ('A' <= word[idx] && word[idx] <= 'Z') ? UPPER : LOWER;

    if (!(type & allowed_state))
      return false;

    // upper is not allowed after a lower
    if (type == LOWER) {
      allowed_state &= ~UPPER;
    }
    // lower is not allowed after a upper, which is the first char
    else if (idx != 0) {
      allowed_state &= ~LOWER;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  return 0;
}
