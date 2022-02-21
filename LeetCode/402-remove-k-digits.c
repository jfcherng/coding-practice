#include "_leetcode_common.c"

char *removeKdigits(char *num, int k) {
  int num_len = strlen(num);

  // stack
  char *res = malloc((num_len + 1) * sizeof(*res));
  int top_idx = -1; // empty

  for (; *num; ++num) {
    while (k > 0 && top_idx != -1 && res[top_idx] > *num) {
      --top_idx;
      --k;
    }
    // append digit if it's not a leading 0
    if (top_idx != -1 || *num != '0') {
      res[++top_idx] = *num;
    }
  }

  // maybe k is still > 0
  int null_idx = ++top_idx - k;
  if (null_idx < 1) {
    res[0] = '0';
    null_idx = 1;
  }
  res[null_idx] = '\0';
  return res;
}

int main(int argc, char *argv[]) {
  char *res;

  // res = removeKdigits("1432219", 3);
  // res = removeKdigits("10", 2);
  // res = removeKdigits("1107", 1);
  // res = removeKdigits("1234567890", 9);
  // res = removeKdigits("10200", 1);
  res = removeKdigits("10", 2);
  printf("res = %s\n", res);

  return 0;
}
