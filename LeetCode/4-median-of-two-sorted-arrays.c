#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  // make nums1 always shorter
  if (nums1Size > nums2Size)
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

  // the size of the merged array
  int size = nums1Size + nums2Size;
  // the index of the meidan      of the merged array if total number of elements are odd
  // or,              left median                                                     even
  int k = (size + 1) / 2;

  // first/last possible partition index
  int l = 0, r = nums1Size;
  while (l <= r) {
    int mid = (l + r) / 2;

    // get the first parititoin1 elements from nums1 and merge it with the first partition2 elements from nums2
    int partition1 = mid;
    int partition2 = k - partition1;

    // 4 elements on the partition boundaries: i.e., (partition1/partition1)'s' (left/right)
    int max_l1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
    int min_r1 = (partition1 == nums1Size) ? INT_MAX : nums1[partition1];
    int max_l2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
    int min_r2 = (partition2 == nums2Size) ? INT_MAX : nums2[partition2];

    // found the answer (all numbers in left partitions <= right partitions)
    if (max_l1 <= min_r2 && max_l2 <= min_r1) {
      return size & 1 ? MAX(max_l1, max_l2)                                // odd
                      : (MAX(max_l1, max_l2) + MIN(min_r1, min_r2)) / 2.0; // even
    }
    // take too make element from nums1
    else if (max_l1 > min_r2) {
      r = partition1 - 1;
    }
    // take too make element from nums2
    else {
      l = partition1 + 1;
    }
  }

  // the compile insists there is a return whatever
  return INT_MIN;
}

int main(int argc, char *argv[]) {
  return 0;
}
