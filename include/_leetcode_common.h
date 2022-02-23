struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct Node {
  int val;
  int numNeighbors;
  struct Node **neighbors;
};
