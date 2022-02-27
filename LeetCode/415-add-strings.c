#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

void stringReverse(char *s, int l, int r) {
  while (l < r) {
    char tmp = s[l];
    s[l++] = s[r];
    s[r--] = tmp;
  }
}

char *addStrings(char *num1, char *num2) {
  // let l1 be the longer string
  int l1 = strlen(num1), l2 = strlen(num2);
  if (l1 < l2) {
    return addStrings(num2, num1);
  }

  char *res = calloc(MAX(l1, l2) + 2, sizeof(*res));

  int res_idx = -1, idx1 = l1, idx2 = l2;
  int carry = 0;

  while (idx1 > 0) {
    int v1 = num1[--idx1] - '0', v2 = idx2 > 0 ? num2[--idx2] - '0' : 0;
    int val = v1 + v2 + carry;
    if (val > 9) {
      carry = 1;
      val -= 10;
    } else {
      carry = 0;
    }
    res[++res_idx] = val + '0';
  }
  if (carry) {
    res[++res_idx] = '1';
  }

  stringReverse(res, 0, res_idx);

  return res;
}

int main(int argc, char *argv[]) {
  char *res = NULL;

  res = addStrings("1", "9");
  printf("res = %s\n", res);
  free(res);

  res = addStrings("11", "123");
  printf("res = %s\n", res);
  free(res);

  res = addStrings("456", "77");
  printf("res = %s\n", res);
  free(res);

  return 0;
}
