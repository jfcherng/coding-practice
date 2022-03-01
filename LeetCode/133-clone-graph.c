#include "_leetcode_common.c"

struct Node {
  int val;
  int numNeighbors;
  struct Node **neighbors;
};

#define MAX_NODE (100)

struct Node *bfs(struct Node *node, struct Node **nodes) {
  if (nodes[node->val])
    return nodes[node->val];

  struct Node *cloned = malloc(sizeof(*cloned));
  nodes[node->val] = cloned;

  cloned->val = node->val;
  cloned->numNeighbors = node->numNeighbors;
  cloned->neighbors = malloc(node->numNeighbors * sizeof(*(cloned->neighbors)));
  for (int i = 0; i < node->numNeighbors; ++i)
    cloned->neighbors[i] = bfs(node->neighbors[i], nodes);

  return cloned;
}

struct Node *cloneGraph(struct Node *node) {
  struct Node *nodes[MAX_NODE + 1] = {}; // all 0 (NULL)
  return node ? bfs(node, nodes) : NULL;
}

int main(int argc, char *argv[]) {
  return 0;
}
