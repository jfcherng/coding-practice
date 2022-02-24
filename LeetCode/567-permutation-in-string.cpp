#include "_leetcode_common.cpp"

template <typename T, size_t N> void printArr(array<T, N> &arr, bool skip_zero = true) {
  for (unsigned int i = 0; i < arr.size(); ++i) {
    if (skip_zero && arr[i] == 0)
      continue;
    cout << ((char) (i + 'a')) << "(" << arr[i] << ") ";
  }
  cout << endl;
}

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    unsigned int l1 = s1.length(), l2 = s2.length();

    if (l1 > l2)
      return false;

    // init cnt1, cnt2
    array<int, 26> cnt1 = {0}, cnt2 = {0};
    for (unsigned int i = 0; i < l1; ++i) {
      cnt1[s1[i] - 'a'] += 1;
      cnt2[s2[i] - 'a'] += 1;
    }

    // sliding window
    for (unsigned int i = 0; i < l2 - l1; ++i) {
      if (isMatched(cnt1, cnt2))
        return true;
      cnt2[s2[i + l1] - 'a'] += 1;
      cnt2[s2[i] - 'a'] -= 1;
    }

    return isMatched(cnt1, cnt2);
  }

private:
  bool isMatched(array<int, 26> const &a, array<int, 26> const &b) {
    for (unsigned int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();

  auto res_1 = s.checkInclusion("ab", "eidboaoo");
  cout << res_1 << endl;
  auto res_2 = s.checkInclusion("adc", "zcda");
  cout << res_2 << endl;

  return 0;
}
