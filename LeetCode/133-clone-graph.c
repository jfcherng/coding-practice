#include "_leetcode_common.c"

struct Node {
  int val;
  int numNeighbors;
  struct Node **neighbors;
};

#define MAX_NODE_CNT (100)

struct Node *dfs(struct Node *node, struct Node **nodes) {
  if (!node)
    return NULL;

  if (nodes[node->val])
    return nodes[node->val];

  struct Node *cloned = calloc(1, sizeof(*cloned));
  nodes[node->val] = cloned;

  cloned->val = node->val;
  cloned->numNeighbors = node->numNeighbors;
  cloned->neighbors = calloc(node->numNeighbors, sizeof(*(cloned->neighbors)));
  for (int i = 0; i < node->numNeighbors; ++i)
    cloned->neighbors[i] = dfs(node->neighbors[i], nodes);

  return cloned;
}

struct Node *cloneGraph(struct Node *node) {
  // cache for cloned nodes
  struct Node *nodes[MAX_NODE_CNT + 1] = {0}; // all 0 (NULL)
  return dfs(node, nodes);
}

int main(int argc, char *argv[]) {
  return 0;
}
