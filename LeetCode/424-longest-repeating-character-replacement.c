#include "_leetcode_common.h"

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct {
  int c; // the char (in ASCII form)
  int freq;
  UT_hash_handle hh;
} CharCounter;

CharCounter *createOrUpdateCounter(int *max_freq, CharCounter **pool, int chr, int increment) {
  CharCounter *out;

  HASH_FIND_INT(*pool, &chr, out);
  if (out) {
    out->freq += increment;
  } else {
    out = malloc(sizeof(*out));
    out->c = chr;
    out->freq = increment;
    HASH_ADD_INT(*pool, c, out);
  }

  // we don't have to decrese this when we move the l pointer
  // becauset to maximize the res, we need to have a larger max_freq in later loops
  *max_freq = MAX(*max_freq, out->freq);

  return out;
}

int characterReplacement(char *s, int k) {
  int res = 0;

  // sliding window
  char *l = s, *r = s;

  int max_freq = 0;
  CharCounter *out, *pool = NULL;

  while (*r) {
    // update the table for char of r pointed to
    createOrUpdateCounter(&max_freq, &pool, *r, 1);

    int length = r - l + 1;
    int change_cnt = length - max_freq;
    // allowed
    if (change_cnt <= k) {
      res = MAX(res, length);
    }
    // disallowed, we need to move the l pointer
    else {
      createOrUpdateCounter(&max_freq, &pool, *l, -1);
      ++l;
    }

    ++r;
  }

  return res;
}

int main(int argc, char *argv[]) {
  printf("characterReplacement(%s, %d) = %d (4)\n", "ABAB", 2, characterReplacement("ABAB", 2));
  printf("characterReplacement(%s, %d) = %d (4)\n", "AABABBA", 1, characterReplacement("AABABBA", 1));

  return 0;
}
