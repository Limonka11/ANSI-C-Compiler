#ifndef LEXER_H
#define LEXER_H

extern int yylex(void);
extern void yyerror(const char*);

extern char* yytext;

#endif