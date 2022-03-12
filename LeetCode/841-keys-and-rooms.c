#include "_leetcode_common.c"

bool all(bool *arr, int arrSize) {
  for (int i = 0; i < arrSize; ++i)
    if (!arr[i])
      return false;
  return true;
}

void dfs(int idx, int **rooms, int roomsSize, int *roomsColSize, bool *visited) {
  if (visited[idx])
    return;

  visited[idx] = true;
  for (int i = 0; i < roomsColSize[idx]; ++i)
    dfs(rooms[idx][i], rooms, roomsSize, roomsColSize, visited);
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize) {
  bool *visited = calloc(roomsSize, sizeof(*visited));
  dfs(0, rooms, roomsSize, roomsColSize, visited);
  return all(visited, roomsSize);
}

int main(int argc, char *argv[]) {
  return 0;
}
