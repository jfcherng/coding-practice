#include "_leetcode_common.h"

#define debug 1

typedef int *Event;

void print_events(Event *events, const int eventsSize) {
  if (!debug)
    return;

  for (int i = 0; i < eventsSize; ++i) {
    Event event = events[i];
    printf("events[%d][] = [ %d, %d, %d ]\n", i, event[0], event[1], event[2]);
  }
}

void print_dp(int *dp, int size) {
  if (!debug)
    return;

  printf("dp[] = [ ");
  for (int i = 0; i < size; ++i) {
    printf("%d, ", dp[i]);
  }
  printf(" ]\n");
}

int sort_by_starting_time(const void *a, const void *b) {
  const Event c = *(Event *) a;
  const Event d = *(Event *) b;

  if (c[0] == d[0]) {
    return 0;
  }
  return c[0] > d[0] ? 1 : -1;
}

// returns the insertion index (prefer higher)
int binary_search(int *arr, int size, int niddle) {
  int low = 0, high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] <= niddle) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return low;
}

int maxTwoEvents(Event *events, int eventsSize, int *eventsColSize) {
  // sort events by starting time
  qsort(events, eventsSize, sizeof(Event), sort_by_starting_time);
  print_events(events, eventsSize);

  // the max event score of each timing which is after its starting time
  int *dp = malloc((eventsSize + 1) * sizeof(int));
  dp[eventsSize] = 0;
  for (int i = eventsSize - 1; i >= 0; --i) {
    dp[i] = (int) fmax(dp[i + 1], events[i][2]);
  }
  print_dp(dp, eventsSize);

  int *t_starts = malloc(eventsSize * sizeof(int));
  for (int i = 0; i < eventsSize; ++i) {
    t_starts[i] = events[i][0];
  }

  int score = 0;
  for (int i = 0; i < eventsSize; ++i) {
    int p = binary_search(t_starts, eventsSize, events[i][1]);

    if (p <= i || p >= eventsSize) {
      // cannot select another event, which is after this event
      score = (int) fmax(score, events[i][2]);
    } else {
      score = (int) fmax(score, events[i][2] + dp[p]);
    }
  }

  return score;
}

int main(int argc, char *argv[]) {
  int eventsSize;
  int eventsColSize = 3;

  eventsSize = 3;
  Event *t_1 = malloc(eventsSize * sizeof(Event));
  int d_1[3][3] = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
  for (int i = 0; i < eventsSize; ++i) {
    t_1[i] = d_1[i];
  }
  int r_1 = maxTwoEvents(t_1, 3, &eventsColSize);
  printf("Ans: %d\n", r_1);

  eventsSize = 3;
  Event *t_2 = malloc(eventsSize * sizeof(Event));
  int d_2[3][3] = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}};
  for (int i = 0; i < eventsSize; ++i) {
    t_2[i] = d_2[i];
  }
  int r_2 = maxTwoEvents(t_2, 3, &eventsColSize);
  printf("Ans: %d\n", r_2);

  return 0;
}
