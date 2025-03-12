#ifndef QUEUE_H_
#define QUEUE_H_

#define NODE_IMPLEMENTATION
#include "node.h"

typedef struct QueueNode {
  Node *val;
  struct QueueNode *left, *right;
} QueueNode;

typedef struct Queue {
  QueueNode *first, *last;
} Queue;

QueueNode *newQueueNode(Node *n);
Queue *newQueue(void);
void enqueue(Queue *q, Node *n);
Node *dequeue(Queue *q);
void freeQueue(Queue *q);

#ifdef QUEUE_IMPLEMENTATION
QueueNode *newQueueNode(Node *n) {
  QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
  qn->val = n;
  qn->left = qn->right = NULL;
  return qn;
}

Queue *newQueue(void) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->first = q->last = NULL;
  return q;
}

void enqueue(Queue *q, Node *n) {
  n->right = NULL;
  QueueNode *qn = newQueueNode(n);

  int qEmpty = !q->first;
  if (qEmpty) {
    q->first = q->last = qn;
    return;
  }

  q->last->right = qn;
  q->last = qn;
}

Node *dequeue(Queue *q) {
  int qEmpty = !q->first;
  if (qEmpty)
    return NULL;

  QueueNode *prevFirst = q->first;
  q->first = q->first->right;

  qEmpty = !q->first;
  if (qEmpty)
    q->last = NULL;

  Node *n = prevFirst->val;
  free(prevFirst);

  return n;
}
#endif // QUEUE_IMPLEMENTATION
void freeQueue(Queue *q) {
  if (!q)
    return;
  while (dequeue(q)) {
  }
  free(q);
}

#endif // QUEUE_H_
