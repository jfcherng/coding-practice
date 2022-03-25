#include "_leetcode_common.c"

int rangeBitwiseAnd_my(int l, int r) {
  int res = 0, p2 = 1 << 30;

  // find common leading parts
  while (p2) {
    if ((p2 & l) != (p2 & r))
      break;

    res |= p2 & r;
    p2 >>= 1;
  }

  return res;
}

int rangeBitwiseAnd(int l, int r) {
  // find common leading parts
  return r > l ? (rangeBitwiseAnd(l >> 1, r >> 1) << 1) : r /* i.e., r==l */;
}

int main(int argc, char *argv[]) {
  printf("res = %d (0)\n", rangeBitwiseAnd(2, 4));

  return 0;
}
