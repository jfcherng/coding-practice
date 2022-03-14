#include "_leetcode_common.c"

// char -> cnt
int counter[128] = {0};

void _heapify(unsigned char *heap, int heapLen, int idx) {
  int rootIdx = idx, l = (idx << 1) + 1, r = (idx << 1) + 2;
  if (l < heapLen && counter[heap[l]] > counter[heap[rootIdx]])
    rootIdx = l;
  if (r < heapLen && counter[heap[r]] > counter[heap[rootIdx]])
    rootIdx = r;
  if (rootIdx != idx) {
    int tmp = heap[idx];
    heap[idx] = heap[rootIdx];
    heap[rootIdx] = tmp;
    _heapify(heap, heapLen, rootIdx);
  }
}

void makeHeap(unsigned char *heap, int heapLen) {
  for (int i = (heapLen - 1) >> 1; i >= 0; --i)
    _heapify(heap, heapLen, i);
}

char heapPop(unsigned char *heap, int *heapLen) {
  char res = heap[0];
  heap[0] = heap[*heapLen - 1];
  --(*heapLen);
  _heapify(heap, *heapLen, 0);
  return res;
}

char *frequencySort(char *s) {
  int len = strlen(s);
  char *res = malloc((len + 1) * sizeof(*res));
  int resIdx = -1;

  unsigned char *heap = malloc(128 * sizeof(*heap));
  int heapLen = 0;
  for (int i = 0; i < len; ++i) {
    if (counter[(unsigned char) s[i]]++ == 0) {
      heap[heapLen] = s[i];
      ++heapLen;
    }
  }

  makeHeap(heap, heapLen);

  while (heapLen) {
    unsigned char c = heapPop(heap, &heapLen);
    while (counter[c]) {
      res[++resIdx] = c;
      --counter[c];
    }
  }

  res[len] = '\0';
  return res;
}

int main(int argc, char *argv[]) {
  printf("%s (eert)\n", frequencySort("tree"));
  printf("%s (eeeeaaarrd)\n", frequencySort("raaeaedere"));
  return 0;
}
