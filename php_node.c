#include "php_node.h"

static Node *tree_root;

void set_tree(Node *p) {
  tree_root = p;
}

Node *get_tree(void) {
  return tree_root;
}

Node *node_alloc(void) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  return p;
}

Node *node_new(NodeType t, Node *left, Node *right) {
  Node *p;
  p = node_alloc();
  p->type = t;
  p->left  = left;
  p->right = right;
  return p;
}

Node *node_num_new(double v) {
  Node *p;
  p = node_alloc();
  p->type = OP_NUM;
  p->val  = v;
  p->left  = NULL;
  p->right = NULL;
  return p;
}

void free_tree(Node *p) {
  if(p == NULL) return;

  Node *left;
  Node *right;
  left  = p->left;
  right = p->right;

  free(p);
  if(left != NULL)
    free_tree(left);
  if(right != NULL)
    free_tree(right);
}

double eval_tree(Node *p) {
  NodeType t;
  double ret;

  t = p->type;
  switch(t){
  case OP_NUM:
    ret =  p->val;
    break;
  case OP_ADD:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case OP_SUB:
    ret = eval_tree(p->left) - eval_tree(p->right);
    break;
  case OP_MUL:
    ret = eval_tree(p->left) * eval_tree(p->right);
    break;
  case OP_DIV:
    ret = eval_tree(p->left) / eval_tree(p->right);
    break;
  case OP_NEG:
    ret = eval_tree(p->left) * -1;
    break;
  }
  return ret;
}
