#include "_leetcode_common.c"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findAnagrams(char *s, char *p, int *returnSize) {
  int *res = malloc(strlen(s) * sizeof(*res));
  *returnSize = 0;

  const int pLen = strlen(p);
  const int sLen = strlen(s);
  if (sLen < pLen)
    return res;

  // count chars in p
  int pCounter[26] = {0};
  for (int i = 0; i < pLen; ++i) {
    ++pCounter[p[i] - 'a'];
  }

  int diffCount = pLen;
  int l = 0, r = 0;
  while (r < sLen) {
    if (pCounter[s[r] - 'a'] > 0) {
      --pCounter[s[r] - 'a'];
      --diffCount;
      ++r;
    } else {
      while (l < r && pCounter[s[r] - 'a'] == 0) {
        ++pCounter[s[l] - 'a'];
        ++diffCount;
        ++l;
      }
      // the char at r is not in p, skip that char
      if (pCounter[s[r] - 'a'] == 0) {
        l = r = r + 1;
        continue;
      }
    }

    if (diffCount == 0) {
      res[(*returnSize)++] = l;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  char *s = "cbaebabacd", *p = "abc";
  int returnSize;
  int *res = findAnagrams(s, p, &returnSize);

  printList(res, returnSize);

  return 0;
}
