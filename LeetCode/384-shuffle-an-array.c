#include "_leetcode_common.c"

typedef struct {
  int *nums;
  int *numsBak;
  int numsSize;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
  srand(time(NULL));

  Solution *obj = malloc(sizeof(*obj));
  obj->nums = nums;
  obj->numsBak = malloc(numsSize * sizeof(*nums));
  obj->numsSize = numsSize;
  memcpy(obj->numsBak, obj->nums, obj->numsSize * sizeof(*(obj->nums)));
  return obj;
}

int *solutionReset(Solution *obj, int *retSize) {
  *retSize = obj->numsSize;
  memcpy(obj->nums, obj->numsBak, obj->numsSize * sizeof(*(obj->numsBak)));
  return obj->nums;
}

int *solutionShuffle(Solution *obj, int *retSize) {
  *retSize = obj->numsSize;
  for (int i = obj->numsSize - 1; i >= 0; --i) {
    int r = rand() % (i + 1);
    // swap
    if (i != r) {
      obj->nums[i] ^= obj->nums[r];
      obj->nums[r] ^= obj->nums[i];
      obj->nums[i] ^= obj->nums[r];
    }
  }
  return obj->nums;
}

void solutionFree(Solution *obj) {
  free(obj->nums);
  free(obj->numsBak);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/

int main(int argc, char *argv[]) {
  int retSize = -1;

  int nums[] = {1, 2, 3};
  int numsSize = sizeof(nums) / sizeof(int);

  Solution *obj = solutionCreate(nums, numsSize);
  // printf("x");
  int *param_1 = solutionReset(obj, &retSize);
  // printf("y");
  int *param_2 = solutionShuffle(obj, &retSize);
  // printf("z");
  printList(param_2, retSize);
  solutionFree(obj);

  return 0;
}
