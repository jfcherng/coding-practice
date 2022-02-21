#include "_leetcode_common.c"

#define GO_DOWN (1 << 0)
#define GO_UP (1 << 1)

bool validMountainArray(int *arr, int arrSize) {
  if (arrSize < 3)
    return false;

  int l = 0, r = arrSize - 1;
  while (l < arrSize - 1 && arr[l] < arr[l + 1])
    ++l;
  while (r > 0 && arr[r - 1] > arr[r])
    --r;

  return l == r && l != 0 && r != arrSize - 1;
}

bool validMountainArray3(int *arr, int arrSize) {
  if (arrSize < 3)
    return false;

  int state = GO_UP, allowed_state = GO_UP;
  for (int i = 1; i < arrSize; ++i) {
    if (arr[i] > arr[i - 1])
      state = GO_UP;
    else if (arr[i] < arr[i - 1])
      state = GO_DOWN;
    else
      return false;

    if (!(state & allowed_state))
      return false;

    if (state == GO_DOWN)
      allowed_state = GO_DOWN;
    else if (state == GO_UP)
      allowed_state = GO_UP | GO_DOWN;
  }

  return state == GO_DOWN;
}

bool validMountainArray2(int *arr, int arrSize) {
  if (arrSize < 3)
    return false;

  int top_cnt = 0, bottom_cnt = 0;

  for (int i = 1; i < arrSize - 1; ++i) {
    if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1])
      return false;

    if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]))
      ++top_cnt;
    if ((arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))
      ++bottom_cnt;
  }

  return top_cnt == 1 && bottom_cnt == 0;
}

int main(int argc, char *argv[]) {
  return 0;
}
