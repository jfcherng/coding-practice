#include "_leetcode_common.c"

typedef struct {
  int c; // key (char)
  char *ptr;
  UT_hash_handle hh;
} hash_entry;

int lengthOfLongestSubstring(char *s) {
  int ans = 0;
  hash_entry *out, *node, *pool = NULL;

  char *l = s, *r = s; // sliding window cursors
  for (; *r; ++r) {
    int k = *r;
    HASH_FIND_INT(pool, &k, out);

    if (!out) {
      node = malloc(sizeof(*node));
      node->c = *r;
      node->ptr = r;
      HASH_ADD_INT(pool, c, node);
      out = node;
    }

    // is duplicate?
    if (out->ptr >= l && out->ptr < r) {
      l = out->ptr + 1; // point to the next distanct char
    }

    out->ptr = r;
    ans = fmax(ans, r - l + 1);
  }

  return ans;
}

int main(int argc, char *argv[]) {
  int ans_1 = lengthOfLongestSubstring("abcabcbb");
  printf("ans_1 = %d (2)\n", ans_1);
  int ans_2 = lengthOfLongestSubstring("bbbbb");
  printf("ans_2 = %d (1)\n", ans_2);
  int ans_3 = lengthOfLongestSubstring("pwwkew");
  printf("ans_3 = %d (3)\n", ans_3);
  int ans_4 = lengthOfLongestSubstring("aab");
  printf("ans_4 = %d (2)\n", ans_4);
  int ans_5 = lengthOfLongestSubstring("dvdf");
  printf("ans_5 = %d (3)\n", ans_5);
  int ans_6 = lengthOfLongestSubstring("tmmzuxt");
  printf("ans_6 = %d (5)\n", ans_6);
  int ans_7 = lengthOfLongestSubstring("aabaab!bb");
  printf("ans_7 = %d (3)\n", ans_7);

  return 0;
}
