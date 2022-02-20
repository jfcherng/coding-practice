#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(const string s) {
    stack<int> stk;
    stk.push(-1);
    int maxL = 0;
    for (int i = 0; i < s.size(); ++i) {
      const int t = stk.top();
      // matched
      if (t != -1 && s[t] == '(' && s[i] == ')') {
        stk.pop();
        maxL = max(maxL, i - stk.top());
      } else
        stk.push(i);
    }
    return maxL;
  }
};
