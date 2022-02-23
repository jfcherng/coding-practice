#include "_leetcode_common.c"

//           2   3
// x         4   5
// ---------------
//          10  15
// +     8  12
// ---------------
//       8  22  15
// ---------------
//       8  23   5
// ---------------
//      10   3   5
// ---------------
//   1   0   3   5
char *multiply(char *num1, char *num2) {
  int l1 = strlen(num1), l2 = strlen(num2);

  int tmp_size = l1 + l2;
  int *tmp = calloc(tmp_size, sizeof(*tmp)); // reversed, LSB is at index 0
  for (int j = l2 - 1; j >= 0; --j)
    for (int i = l1 - 1; i >= 0; --i)
      tmp[(l1 - 1 - i) + (l2 - 1 - j)] += (num1[i] - '0') * (num2[j] - '0');
  // MSB never has carry
  for (int i = 0; i < tmp_size - 1; ++i) {
    tmp[i + 1] += tmp[i] / 10; // carry
    tmp[i] %= 10;
  }

  int k = tmp_size - 1; // the index of MSB
  while (k > 0 && tmp[k] == 0)
    --k;                                   // index 0 ~ k are valid digits
  char *res = calloc(k + 2, sizeof(*res)); // 0 ~ k = k+1 digits and then +1 for \0
  for (int i = k; i >= 0; --i)
    res[k - i] = tmp[i] + '0';

  free(tmp);
  return res;
}

int main(int argc, char *argv[]) {
  char *res = multiply("123", "456");
  printf("res = %s\n", res);

  return 0;
}
