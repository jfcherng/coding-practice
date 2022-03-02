#include "_leetcode_common.c"

// mask keeps the hash = 10 chars * 2 bits = 20 bits
#define HASH_MASK ((1 << 20) - 1)

typedef struct {
  int key; // hash of DNA 10-char
  int cnt;
  UT_hash_handle hh;
} DnaSeg;

DnaSeg *createDnaSeg(int key, int cnt) {
  DnaSeg *res = malloc(sizeof(*res));
  res->key = key;
  res->cnt = cnt;
  return res;
}

char **findRepeatedDnaSequences(char *s, int *returnSize) {
  *returnSize = 0;

  int sLen = strlen(s);
  if (sLen < 10) {
    return NULL;
  }

  // hash an 'A', 'C', 'G' or 'T' into 2 bits
  unsigned short c2h[99] = {0};
  c2h['A'] = 0, c2h['C'] = 1, c2h['G'] = 2, c2h['T'] = 3;

  char **res = calloc(sLen, sizeof(*res));
  DnaSeg *out = NULL, *pool = NULL;

  int hash = 0;
  for (int i = 0; i < sLen; ++i) {
    hash = ((hash << 2) | c2h[(int) s[i]]) & HASH_MASK;

    // out of boundaries
    if (i < 9)
      continue;

    HASH_FIND_INT(pool, &hash, out);
    if (!out) {
      out = createDnaSeg(hash, 0);
      HASH_ADD_INT(pool, key, out);
    }
    if (++out->cnt == 2) {
      char *tmp = calloc(11, sizeof(*tmp));
      memcpy(tmp, s + i - 9, 10);
      res[(*returnSize)++] = tmp;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  char **res = NULL;
  int resSize = 0;

  res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", &resSize);
  for (int i = 0; i < resSize; ++i) {
    printf("Found '%s'\n", res[i]);
  }
  printf("\n\n");

  return 0;
}
