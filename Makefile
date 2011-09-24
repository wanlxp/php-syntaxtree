TARGET = php
BISON_SRC = php_language_parser.y
BISON_H   = php_language_parser.tab.h
BISON_C   = php_language_parser.tab.c
BISON_O   = php_language_parser.tab.o
BISON_OUT = $(BISON_C) $(BISON_H) php_language_parser.output
FLEX_SRC  = php_language_scanner.l
FLEX_C    = lex.yy.c
FLEX_O    = lex.yy.o
C_FILES   = $(BISON_C) $(FLEX_C) php_node.c main.c
OBJ       = $(FLEX_O) $(BISON_O) php_node.o main.o

all : $(TARGET)

$(TARGET) : $(OBJ)
	gcc -o $@ $(OBJ)

$(FLEX_C) : $(FLEX_SRC) $(BISON_H)
	flex $(FLEX_SRC)

$(BISON_OUT) : $(BISON_SRC)
	bison -dv $(BISON_SRC)

.c.o :
	gcc -c $<


clean :
	rm -f lex.yy.c php_language_parser.tab.c
	rm -f lex.yy.h php_language_parser.tab.c
	rm -f php_language_parser.tab.h
	rm -f *.output
	rm -f *.o
	rm -f $(TARGET)

lex.yy.o: lex.yy.c php_language_parser.tab.h
php_language_parser.tab.o: php_language_parser.tab.c php_language_parser.tab.h php_node.h
php_node.o: php_node.c php_node.h
main.o: main.c php_node.h