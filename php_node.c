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
  p->type = N_LNUMBER;
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
  case N_EXIT:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_IF:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_LNUMBER:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_DNUMBER:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_STRING:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_STRING_VARNAME:
    ret = eval_tree(p->left) + eval_tree(p->right);
    break;
  case N_VARIABLE:
    ret =  p->val;
    break;
  }
  return ret;
}
