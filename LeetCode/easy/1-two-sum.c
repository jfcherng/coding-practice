#include "_leetcode_common.h"

void print_arr(char *name, int *arr, int size) {
  printf("%s = [ ", name);
  for (int i = 0; i < size; ++i) {
    printf("%d, ", arr[i]);
  }
  printf(" ]\n");
}

typedef struct {
  int *value;
  int index;
} num_info;

int sort_num_infos(const void *a, const void *b) {
  int *v1 = ((num_info *) a)->value;
  int *v2 = ((num_info *) b)->value;
  if (*v1 == *v2) {
    return 0;
  }
  return *v1 > *v2 ? 1 : -1;
}

int binary_search(num_info *arr, int l, int r, int target) {
  while (r >= l) {
    int mid = (l + r) / 2;

    if (*arr[mid].value == target) {
      return mid;
    }

    if (*arr[mid].value > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

typedef struct {
  int value; // key
  int index; // value
  UT_hash_handle hh;
} hash_entry;

int *twoSum_uthash(int *nums, int numsSize, int target, int *returnSize) {
  int *ans = malloc(2 * sizeof(int));
  hash_entry *s, *pool = NULL;

  // construct hash table
  for (int i = 0; i < numsSize; ++i) {
    s = malloc(sizeof(hash_entry));
    s->value = nums[i];
    s->index = i;
    HASH_ADD_INT(pool, value, s);
  }

  for (int i = 0; i < numsSize; ++i) {
    int target_new = target - nums[i];

    HASH_FIND_INT(pool, &target_new, s);
    if (s && i < s->index) {
      ans[0] = i;
      ans[1] = s->index;
      *returnSize = 2;

      // free here
      return ans;
    }
  }

  printf("NOT FOUND\n");
  return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *ans = malloc(2 * sizeof(int));

  // num_infos logs the original value/index of all input nums
  num_info *num_infos = malloc(numsSize * sizeof(*num_infos));
  for (int i = 0; i < numsSize; ++i) {
    num_info tmp;
    tmp.index = i;
    tmp.value = &nums[i];
    num_infos[i] = tmp;
  }

  qsort(num_infos, numsSize, sizeof(*num_infos), sort_num_infos);

  for (int i = 0; i < numsSize - 1; ++i) {
    int new_target = target - *num_infos[i].value;

    int pos = binary_search(num_infos, i + 1, numsSize - 1, new_target);
    if (pos == -1) {
      continue;
    }

    ans[0] = num_infos[i].index;
    ans[1] = num_infos[pos].index;
    *returnSize = 2;

    if (ans[0] > ans[1]) {
      int tmp = ans[0];
      ans[0] = ans[1];
      ans[1] = tmp;
    }

    free(num_infos);
    return ans;
  }

  printf("NOT FOUND\n");
  return ans;
}

int main(int argc, char *argv[]) {
  int numsSize;
  int *nums;
  int target;

  int *ans;
  int returnSize;

  int nums_1[] = {2, 7, 11, 15};
  target = 9;
  nums = nums_1;
  numsSize = sizeof(nums_1) / sizeof(int);
  ans = twoSum_uthash(nums, numsSize, target, &returnSize);
  print_arr("ans", ans, returnSize);
  free(ans);

  int nums_2[] = {3, 2, 4};
  target = 6;
  nums = nums_2;
  numsSize = sizeof(nums_2) / sizeof(int);
  ans = twoSum_uthash(nums, numsSize, target, &returnSize);
  print_arr("ans", ans, returnSize);
  free(ans);

  int nums_3[] = {3, 2, 3};
  target = 6;
  nums = nums_3;
  numsSize = sizeof(nums_3) / sizeof(int);
  ans = twoSum_uthash(nums, numsSize, target, &returnSize);
  print_arr("ans", ans, returnSize);
  free(ans);

  return 0;
}
