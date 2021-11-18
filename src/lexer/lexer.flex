%option noyywrap
%option yylineno

%{
#include <iostream>
#include <regex>
#include <queue>

#include "parser.tab.hpp"
#include "lexer.hpp"
#include "AST.hpp"

// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

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
WHITESPACE              [ \t]+

%%

;    { return (SEMICOLON); }
=    { return (EQUALS); }
\(   { return (LBRACKET); }
\)   { return (RBRACKET); }
\{   { return (LCURLY); }
\}   { return (RCURLY); }
,    { return (COMMA); }
\[   { return (LSQUARE); }
\]   { return (RSQUARE); }
\.   { return (FULLSTOP); }
\+\+ { return (INCREMENT); }
--   { return (DECREMENT); }
&    { return (AMPERSAND); }
\*   { return (ASTERISK); }
\+   { return (PLUS); }
-    { return (MINUS); }
~    { return (TILDE); }
!    { return (EXCLAMATION); }
\/   { return (FRONTSLASH); }
\%   { return (PERCENT); }
\<\< { return (LSHIFT); }
>>   { return (RSHIFT); }
\<   { return (LESS); }
>    { return (GREATER); }
\<=  { return (LESS_EQUAL); }
>=   { return (GREATER_EQUAL); }
==   { return (EQUAL_EQUAL); }
!=   { return (NOT_EQUAL); }
\^   { return (XOR); }
\|   { return (OR); }
&&   { return (LOGICAL_AND); }
\|\| { return (LOGICAL_OR); }
\?   { return (QUESTION); }
\:   { return (COLON); }
\+=  { return (EQUALS_ADD); }
\-=  { return (EQUALS_SUB); }

float  { return (FLOAT);}
void   { return (VOID); }
int    { return (INT); }
if     { return (IF); }
else   { return (ELSE); }
while  { return (WHILE); }
for    { return (FOR); }
return { return (RETURN); }

{IDENTIFIER}        { yylval.str = new std::string(yytext); return IDENTIFIER; }
{INT_CONSTANT}      { yylval.str = new std::string(yytext); return INT_CONSTANT; }
{CHAR_CONSTANT}     { yylval.str = new std::string(yytext); return CHAR_CONSTANT; }
{FLOAT_CONSTANT}    { yylval.str = new std::string(yytext); return FLOAT_CONSTANT; }
{WHITESPACE}        { ; }

. { fprintf(stderr, "Not a regex"); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s);
  exit(1);
}