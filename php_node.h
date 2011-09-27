#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef enum {
    N_EXIT = 1,
    N_IF,
    N_LNUMBER,
    N_DNUMBER,
    N_STRING,
    N_STRING_VARNAME,
    N_VARIABLE,
    N_NUM_STRING,
    N_INLINE_HTML,
    N_CHARACTER,
    N_BAD_CHARACTER,
    N_ENCAPSED_AND_WHITESPACE,
    N_CONSTANENCAPSED_STRING,
    N_ECHO,
    N_DO,
    N_WHILE,
    N_ENDWHILE,
    N_FOR,
    N_ENDFOR,
    N_FOREACH,
    N_ENDFOREACH,
    N_DECLARE,
    N_ENDDECLARE,
    N_AS,
    N_SWITCH,
    N_ENDSWITCH,
    N_CASE,
    N_DEFAULT,
    N_BREAK,
    N_CONTINUE,
    N_GOTO,
    N_FUNCTION,
    N_CONST,
    N_RETURN,
    N_TRY,
    N_CATCH,
    N_THROW,
    N_USE,
    N_GLOBAL,
    N_VAR,
    N_UNSET,
    N_ISSET,
    N_EMPTY,
    N_HALCOMPILER,
    N_CLASS,
    N_INTERFACE,
    N_EXTENDS,
    N_IMPLEMENTS,
    N_OBJECOPERATOR,
    N_DOUBLE_ARROW,
    N_LIST,
    N_ARRAY,
    N_CLASS_C,
    N_METHOD_C,
    N_FUNC_C,
    N_LINE,
    N_FILE,
    N_COMMENT,
    N_DOC_COMMENT,
    N_OPEN_TAG,
    N_OPEN_TAG_WITH_ECHO,
    N_CLOSE_TAG,
    N_WHITESPACE,
    N_STARHEREDOC,
    N_END_HEREDOC,
    N_DOLLAR_OPEN_CURLY_BRACES,
    N_CURLY_OPEN,
    N_PAAMAYIM_NEKUDOTAYIM,
    N_NAMESPACE,
    N_NS_C,
    N_DIR,
    N_NS_SEPARATOR
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
