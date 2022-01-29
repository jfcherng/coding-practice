#include "_leetcode_common.h"
#include <stdio.h>

typedef struct {
  int chr;
  int cnt;
  UT_hash_handle hh;
} Counter;

Counter *createNewCounter(int chr) {
  Counter *new = malloc(sizeof(*new));
  new->chr = chr;
  new->cnt = 1;
  return new;
}

void pop_at_l(Counter *pool, char *s, int *l, int *total_cnt) {
  Counter *out;
  int key = s[*l];
  HASH_FIND_INT(pool, &key, out);
  if (out) {
    ++out->cnt;
    ++*total_cnt;
  }
  ++*l;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findAnagrams(char *s, char *p, int *returnSize) {
  int *res = malloc(strlen(s) * sizeof(*res));
  *returnSize = 0;

  int p_len = strlen(p);
  int s_len = strlen(s);
  Counter *out, *pool = NULL;

  // count chars in p
  int total_cnt = p_len;
  for (int i = 0; i < total_cnt; ++i) {
    int key = p[i];
    HASH_FIND_INT(pool, &key, out);
    if (out) {
      ++out->cnt;
      continue;
    }
    Counter *tmp = createNewCounter(p[i]);
    HASH_ADD_INT(pool, chr, tmp);
  }

  int l = 0, r = 0;
  while (r < s_len) {
    int key = s[r];
    HASH_FIND_INT(pool, &key, out);
    if (out) {
      if (out->cnt > 0) {
        --out->cnt;
        --total_cnt;
        ++r;
      } else {
        while (s[l] != s[r]) {
          pop_at_l(pool, s, &l, &total_cnt);
        }
        pop_at_l(pool, s, &l, &total_cnt);
      }
    } else {
      while (l < r) {
        pop_at_l(pool, s, &l, &total_cnt);
      }
      l = r = r + 1;
    }

    if (total_cnt == 0) {
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
