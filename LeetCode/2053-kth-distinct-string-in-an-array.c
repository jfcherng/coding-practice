#include "_leetcode_common.h"

typedef struct {
  char *name; /* key (string is WITHIN the structure) */
  int cnt;
  UT_hash_handle hh;
} hash_entry;

char *kthDistinct(char **arr, int arrSize, int k) {
  hash_entry *s, *tmp, *strings = NULL;

  // construct hash
  for (int i = 0; i < arrSize; ++i) {
    HASH_FIND_STR(strings, arr[i], s);
    if (s) {
      s->cnt++;
      continue;
    }

    s = (hash_entry *) malloc(sizeof(hash_entry));
    s->name = arr[i];
    s->cnt = 1;
    HASH_ADD_KEYPTR(hh, strings, s->name, strlen(s->name), s);
  }

  int nth = 0;
  HASH_ITER(hh, strings, s, tmp) {
    if (s->cnt == 1 && ++nth == k) {
      return s->name;
    }
  }
  return "";
}

int main(int argc, char *argv[]) {
  char *in[6] = {"d", "b", "c", "b", "c", "a"};
  char *r = kthDistinct(in, sizeof(in) / sizeof(char *), 2);
  printf("=> Ans: %s\n", r);

  return 0;
}
