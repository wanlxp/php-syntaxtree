#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef enum {
  OP_ADD = 1, 
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_NEG,
  OP_NUM
} NodeType;

typedef struct Node_def Node;
struct Node_def {
  NodeType type;
  double   val;
  Node     *left;
  Node     *right;
};

void set_tree(Node *);
Node *get_tree(void);
Node *node_alloc(void);
Node *node_new(NodeType, Node *, Node *);
Node *node_num_new(double);
void free_tree(Node *);
double eval_tree(Node *);

#endif
