%{
#include <stdio.h>
#include "php_node.h"
#include "php_language_parser.tab.h"

int yywrap(void){ return 1;}
%}

%%
. {}
%%
