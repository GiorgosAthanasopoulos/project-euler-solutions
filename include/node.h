#ifndef NODE_H_
#define NODE_H_

typedef struct Node {
  int val;
  struct Node *left, *right;
} Node;

Node *newNode(int val);
void freeNode(Node *n);

#ifdef NODE_IMPLEMENTATION
#include <malloc.h>
#include <stdlib.h>

Node *newNode(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->left = node->right = NULL;
  return node;
}

void freeNode(Node *n) { free(n); }
#endif // NODE_IMPLEMENTATION

#endif // NODE_H_
