#include "_leetcode_common.c"

int sorter(const void *a, const void *b) {
  return *(int *) a - *(int *) b;
}

int numRescueBoats(int *people, int peopleSize, int limit) {
  qsort(people, peopleSize, sizeof(*people), sorter);

  int res = 0;

  int l = 0, r = peopleSize - 1;
  while (l <= r) {
    // the lightest person can share with the heaviest person
    if (people[l] + people[r] <= limit)
      ++l;
    // the heaviest person takes a boat
    --r;
    ++res;
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
