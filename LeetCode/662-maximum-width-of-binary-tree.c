#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

struct QueueNode {
  struct TreeNode *tn;
  unsigned int idx;
  struct QueueNode *next;
};

struct Queue {
  int count;
  struct QueueNode *head;
  struct QueueNode *tail;
};

struct Queue *createQueue() {
  struct Queue *q = malloc(sizeof(*q));
  q->count = 0;
  q->head = q->tail = NULL;
  return q;
}

struct QueueNode *createQueueNode(struct TreeNode *tn, int idx) {
  struct QueueNode *qn = malloc(sizeof(*qn));
  qn->tn = tn;
  qn->idx = idx;
  qn->next = NULL;
  return qn;
}

void ququePushBack(struct Queue *q, struct QueueNode *qn) {
  if (!q->count) {
    q->head = q->tail = qn;
  } else {
    q->tail = q->tail->next = qn;
  }

  qn->next = NULL;
  ++q->count;
}

struct QueueNode *ququePopFront(struct Queue *q) {
  struct QueueNode *res = q->head;

  if (q->count) {
    q->head = q->head->next;
    --q->count;
  }

  if (!q->head)
    q->tail = NULL;

  if (res)
    res->next = NULL;
  return res;
}

struct QueueNode *ququeFront(struct Queue *q) {
  return q->head;
}

struct QueueNode *ququeBack(struct Queue *q) {
  return q->tail;
}

void printQueue(struct Queue *q) {
  struct QueueNode *p = q->head;

  printf("(count = %d) ", q->count);
  while (p) {
    printf("idx(%d) -> ", p->idx);
    p = p->next;
  }

  printf("NULL\n");
}

int widthOfBinaryTree(struct TreeNode *root) {
  struct Queue *q = createQueue();
  ququePushBack(q, createQueueNode(root, 1));

  int res = 0, count = 0;
  while ((count = q->count)) {
    int w = ququeBack(q)->idx - ququeFront(q)->idx + 1;
    res = MAX(res, w);

    for (int _ = 0; _ < count; ++_) {
      struct QueueNode *qn = ququePopFront(q);
      assert(qn);
      if (qn->tn->left)
        ququePushBack(q, createQueueNode(qn->tn->left, 2 * qn->idx));
      if (qn->tn->right)
        ququePushBack(q, createQueueNode(qn->tn->right, 2 * qn->idx + 1));
      free(qn);
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  struct TreeNode tree = {
      .val = 1,
      .left =
          &(struct TreeNode){
              .val = 3,
              .left =
                  &(struct TreeNode){
                      .val = 5,
                      .left = NULL,
                      .right = NULL,
                  },
              .right = NULL,
          },
      .right =
          &(struct TreeNode){
              .val = 2,
              .left = NULL,
              .right = NULL,
          },
  };

  int res = widthOfBinaryTree(&tree);
  printf("res = %d\n", res);

  return 0;
}
