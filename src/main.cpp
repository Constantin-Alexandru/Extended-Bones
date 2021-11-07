#include "./includes/main.h"

int main()
{
    Lexer lex;

    char program[] = "clear H;\n set H 72;\n printa H;\n    ";

    lex.lex(program);
    return 0;
}