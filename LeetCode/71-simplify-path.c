#include "_leetcode_common.c"

// determinate whether *s starts with *t
bool startswith(char *s, char *t) {
  while (*t) {
    if (!*s || *s != *t) {
      return false;
    }
    ++t, ++s;
  }
  return true;
}

char *simplifyPath(char *path) {
  int len = strlen(path);

  char *res = calloc(len + 2, sizeof(*res));
  strcpy(res, path);
  res[len] = '/'; // make path always ends with '/'

  int *stack = calloc((len >> 1) + 1, sizeof(*stack)); // records indexes of valid '/'
  int resIdx = -1, stackIdx = -1;

  for (int i = 0; i < len;) {
    if (res[i] == '/') {
      while (i < len && res[i] == '/')
        ++i;
      if (resIdx == -1 || res[resIdx] != '/') {
        res[++resIdx] = '/';
        stack[++stackIdx] = resIdx;
      }
      continue;
    }

    assert(i > 0);

    if (res[i - 1] == '/') {
      if (startswith(res + i, "./")) {
        i += 1;
      } else if (startswith(res + i, "../")) {
        if (stackIdx > 0) {
          resIdx = stack[--stackIdx];
        }
        i += 2;
      }
    }

    // regular chars
    while (i < len && res[i] != '/') {
      res[++resIdx] = res[i++];
    }
  }

  // remove trailing '/'
  if (res[resIdx] == '/' && resIdx != 0) {
    --resIdx;
  }

  res[++resIdx] = '\0';
  return res;
}

int main(int argc, char *argv[]) {
  printf("%s (/)\n", simplifyPath("/"));
  printf("%s (/)\n", simplifyPath("/a/.."));
  printf("%s (/a)\n", simplifyPath("/a/./"));
  printf("%s (/c)\n", simplifyPath("/a/../../b/../c//.//"));
  printf("%s (/c)\n", simplifyPath("/a/./b/../../c/"));
  return 0;
}
