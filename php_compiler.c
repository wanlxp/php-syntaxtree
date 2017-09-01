 #include "php_language_parser.tab.h"

int phplex()
{
    int retval;

	/*
    if (CG(increment_lineno)) {
        CG(zend_lineno)++;
        CG(increment_lineno) = 0; 
    }    
	*/

again:
	/*
    Z_TYPE(zendlval->u.constant) = IS_LONG;
    retval = lex_scan(&zendlval->u.constant TSRMLS_CC);
	*/
	retval = yylex();
    switch (retval) {
        case T_COMMENT:
        case T_DOC_COMMENT:
        case T_OPEN_TAG:
        case T_WHITESPACE:
            goto again;

        case T_CLOSE_TAG:
			/*
            if (LANG_SCNG(yy_text)[LANG_SCNG(yy_leng)-1] != '>') {
                CG(increment_lineno) = 1; 
            }    
            if (CG(has_bracketed_namespaces) && !CG(in_namespace)) {
                goto again;     
            }    
			*/
            retval = ';'; /* implicit ; */
            break;
        case T_OPEN_TAG_WITH_ECHO:
            retval = T_ECHO;
            break;
        case T_END_HEREDOC:
            break;
    }    
    return retval;
}
