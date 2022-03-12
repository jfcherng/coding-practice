#include "_leetcode_common.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

const char TREE_END = 0;
const char HAS_NOTHING = 1 << 0;
const char HAS_L = 1 << 1;
const char HAS_R = 1 << 2;

typedef struct {
  char *c;
  unsigned len;
  unsigned capacity;
} DataString;

DataString *createTreeString() {
  DataString *s = malloc(sizeof(DataString));
  s->capacity = 32;
  s->c = malloc(s->capacity * sizeof(char));
  s->c[0] = TREE_END;
  s->len = 0;
  return s;
}

void treeStringAppend(DataString *const s, const void *const c, const int cLen) {
  if (s->len + cLen + 1 >= s->capacity) {
    s->capacity <<= 1;
    s->c = realloc(s->c, s->capacity * sizeof(char));
  }

  memcpy(s->c + s->len, c, cLen);
  s->len += cLen;
  s->c[s->len + 1] = TREE_END;
}

void treeStringDestroy(const DataString **const s) {
  free((*s)->c);
  *s = NULL;
}

/** Encodes a tree to a single string. */
void _serialize(struct TreeNode *root, DataString *s) {
  // state = 1 byte (char)
  // val = 4 bytes (int)
  // we always encode a node into 5 bytes (i.e., 5 chars)

  if (!root)
    return;

  // pre-order DFS

  char status = HAS_NOTHING; // not default to 0 anyway
  if (root->left)
    status |= HAS_L;
  if (root->right)
    status |= HAS_R;
  treeStringAppend(s, &status, sizeof(status));
  treeStringAppend(s, &(root->val), sizeof(root->val));

  _serialize(root->left, s);
  _serialize(root->right, s);
}
char *serialize(struct TreeNode *root) {
  DataString *s = createTreeString();
  _serialize(root, s);
  return s->c;
}

/** Decodes your encoded data to tree. */
struct TreeNode *_deserialize(char *data, int *idx) {
  if (data[*idx] == TREE_END)
    return NULL; // empty tree

  // pre-order DFS

  struct TreeNode *node = malloc(sizeof(*node));
  node->left = node->right = NULL;

  char status = data[(*idx)++];
  memcpy(&(node->val), data + *idx, sizeof(node->val));
  *idx += sizeof(node->val);

  if (status & HAS_L)
    node->left = _deserialize(data, idx);
  if (status & HAS_R)
    node->right = _deserialize(data, idx);

  return node;
}
struct TreeNode *deserialize(char *data) {
  int idx = 0;
  return _deserialize(data, &idx);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
int main(int argc, char *argv[]) {
  int nodes[] = {1, 2, 3, TREENODE_NULL, TREENODE_NULL, 4, 5};
  struct TreeNode *root = createTreeNodesFromList(nodes, sizeof(nodes) / sizeof(int));
  printTreeNodes(root, PRINT_IN_ORDER);

  char *data = serialize(root);
  struct TreeNode *decoded = deserialize(data);
  printTreeNodes(decoded, PRINT_IN_ORDER);

  return 0;
}
