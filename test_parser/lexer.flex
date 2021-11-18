%option noyywrap
%option yylineno

%{
#include <iostream>
#include <regex>
#include <queue>

#include "parser.tab.hpp"
#include "lexer.hpp"
#include "ast.hpp"

// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

int tokenize(int type);
int new_token(int type);
int new_stringLiteral();

%}

IDENTIFIER              [A-Za-z_][A-Za-z_0-9]*

INT_CONSTANT            ({DEC_CONSTANT_INT}|{OCT_CONSTANT_INT}|{HEX_CONSTANT_INT}){CONST_INT_SUFFIX}?
DEC_CONSTANT_INT        [1-9][0-9]*
OCT_CONSTANT_INT        0{OCT_DIGIT}*
OCT_DIGIT               [0-7]
HEX_CONSTANT_INT        0(x|X){HEX_DIGIT}+
HEX_DIGIT               [0-9a-fA-F]
CONST_INT_SUFFIX        {UNSIGNED_INT_SUFFIX}{LONG_INT_SUFFIX}|{LONG_INT_SUFFIX}{UNSIGNED_INT_SUFFIX}
UNSIGNED_INT_SUFFIX     u|U
LONG_INT_SUFFIX         l|L
CHAR_CONSTANT           L?\'{CHAR}+\'
CHAR                    [^\'\n]|{CHAR_ESCAPE}
CHAR_ESCAPE             {CHAR_ESCAPE_SIMPLE}|{CHAR_ESCAPE_OCTAL}|{CHAR_ESCAPE_HEX}
CHAR_ESCAPE_SIMPLE      \\\'|\\\"|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v
CHAR_ESCAPE_OCTAL       \\({OCT_DIGIT}|{OCT_DIGIT}{OCT_DIGIT}|{OCT_DIGIT}{OCT_DIGIT}{OCT_DIGIT})
CHAR_ESCAPE_HEX         \\x{HEX_DIGIT}+
FLOAT_CONSTANT          ({FLOAT_FRACT}{FLOAT_EXP}?|{FLOAT_DIGITS}{FLOAT_EXP}){CONST_FLOAT_SUFFIX}?
FLOAT_FRACT             {FLOAT_DIGITS}?\.{FLOAT_DIGITS}|{FLOAT_DIGITS}\.
FLOAT_EXP               [eE]{FLOAT_SIGN}?{FLOAT_DIGITS}
FLOAT_SIGN              \+|-
FLOAT_DIGITS            [0-9]+
CONST_FLOAT_SUFFIX      f|l|F|L
STRING_LITERAL          L?\"{STRING_CHARS}?\"
STRING_CHARS            ([^\"\n]|{CHAR_ESCAPE})+
PREPROCESSOR            #[^\n]*\n
WHITESPACE              [ \t\r\n]+

%%

;    { return tokenize(T_SEMICOLON); }
=    { return tokenize(T_EQUALS); }
\(   { return tokenize(T_LBRACKET); }
\)   { return tokenize(T_RBRACKET); }
\{   { return tokenize(T_LCURLY); }
\}   { return tokenize(T_RCURLY); }
,    { return tokenize(T_COMMA); }
\[   { return tokenize(T_LSQUARE); }
\]   { return tokenize(T_RSQUARE); }
\.   { return tokenize(T_FULLSTOP); }
->   { return tokenize(T_ARROW); }
\+\+ { return tokenize(T_INCREMENT); }
--   { return tokenize(T_DECREMENT); }
&    { return tokenize(T_AMPERSAND); }
\*   { return tokenize(T_ASTERISK); }
\+   { return tokenize(T_PLUS); }
-    { return tokenize(T_MINUS); }
~    { return tokenize(T_TILDE); }
!    { return tokenize(T_EXCLAMATION); }
\/   { return tokenize(T_FRONTSLASH); }
\%   { return tokenize(T_PERCENT); }
\<\< { return tokenize(T_LSHIFT); }
>>   { return tokenize(T_RSHIFT); }
\<   { return tokenize(T_LESS); }
>    { return tokenize(T_GREATER); }
\<=  { return tokenize(T_LESS_EQUAL); }
>=   { return tokenize(T_GREATER_EQUAL); }
==   { return tokenize(T_EQUAL_EQUAL); }
!=   { return tokenize(T_NOT_EQUAL); }
\^   { return tokenize(T_XOR); }
\|   { return tokenize(T_OR); }
&&   { return tokenize(T_LOGICAL_AND); }
\|\| { return tokenize(T_LOGICAL_OR); }
\?   { return tokenize(T_QUESTION); }
\:   { return tokenize(T_COLON); }
\*=  { return tokenize(T_EQUALS_MUL); }
\/=  { return tokenize(T_EQUALS_DIV); }
%=   { return tokenize(T_EQUALS_MOD); }
\+=  { return tokenize(T_EQUALS_ADD); }
\-=  { return tokenize(T_EQUALS_SUB); }
\<\<= { return tokenize(T_EQUALS_LSHIFT); }
>>=  { return tokenize(T_EQUALS_RSHIFT); }
&=   { return tokenize(T_EQUALS_AND); }
\^=  { return tokenize(T_EQUALS_XOR); }
\|=  { return tokenize(T_EQUALS_OR); }

void   { return tokenize(T_VOID); }
char   { return tokenize(T_CHAR); }
int    { return tokenize(T_INT); }
long   { return tokenize(T_LONG); }
float  { return tokenize(T_FLOAT); }
double { return tokenize(T_DOUBLE); }
if     { return tokenize(T_IF); }
else   { return tokenize(T_ELSE); }
while  { return tokenize(T_WHILE); }
for    { return tokenize(T_FOR); }
return { return tokenize(T_RETURN); }

{IDENTIFIER}        { yylval.str = new std::string(yytext); return T_IDENTIFIER; }
{INT_CONSTANT}      { yylval.str = new std::string(yytext); return T_INT_CONSTANT; }
{CHAR_CONSTANT}     { yylval.str = new std::string(yytext); return T_CHAR_CONSTANT; }
{FLOAT_CONSTANT}    { yylval.str = new std::string(yytext); return T_FLOAT_CONSTANT; }
{WHITESPACE}        { ; }
{STRING_LITERAL}    { return new_stringLiteral(); }


. { fprintf(stderr, "Not a regex"); }

%%

int tokenize(int type) {
     return type;
}

int new_stringLiteral()
{
        tokenize(T_STRING_LITERAL);
        std::string text(yytext);
        text.pop_back();
        text.erase(0, 1);

        strcpy(yytext, const_cast<char*>(text.c_str()));

        yylval.str = new std::string(yytext);

        return T_STRING_LITERAL;
}

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}