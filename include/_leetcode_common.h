#define DEBUG

// a arbitrary value which is not used as a node value
#define TREENODE_NULL (5 - (1 << 30))

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
