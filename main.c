#include <stdio.h>
#include "php_node.h"

extern int yyparse(void);
extern FILE *yyin;
extern int yydebug;


int main(int argc, char ** argv){
  Node *p;
  int ret;

  if((yyin = fopen( argv[1], "r")) == NULL){
    fprintf(stderr,"Can't open a input file!\n");
    return 1;
  }

  ret = yyparse();
  printf("yyparse return : %d\n", ret);
  if(ret == 0){
    p = get_tree();
    if(p == NULL)
      printf("tree is NULL\n");
    else{
      printf("tree value = %g\n", eval_tree(p));
      free_tree(p);
    }
  }
  return ret;
}
