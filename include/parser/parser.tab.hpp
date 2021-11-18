/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "src/parser/parser.y" /* yacc.c:1909  */

        #include "parser.hpp"
        #include "lexer.hpp"

        extern const Node* root;

        extern FILE* yyin;

#line 53 "src/parser/parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_CONSTANT = 258,
    CHAR_CONSTANT = 259,
    FLOAT_CONSTANT = 260,
    IDENTIFIER = 261,
    STRING_LITERAL = 262,
    SEMICOLON = 263,
    LBRACKET = 264,
    RBRACKET = 265,
    LCURLY = 266,
    RCURLY = 267,
    COMMA = 268,
    TILDE = 269,
    EQUALS = 270,
    LSQUARE = 271,
    RSQUARE = 272,
    FULLSTOP = 273,
    ARROW = 274,
    INCREMENT = 275,
    DECREMENT = 276,
    SIZEOF = 277,
    AMPERSAND = 278,
    ASTERISK = 279,
    PLUS = 280,
    MINUS = 281,
    EXCLAMATION = 282,
    FRONTSLASH = 283,
    LSHIFT = 284,
    RSHIFT = 285,
    PERCENT = 286,
    LESS = 287,
    GREATER = 288,
    LESS_EQUAL = 289,
    GREATER_EQUAL = 290,
    EQUAL_EQUAL = 291,
    NOT_EQUAL = 292,
    XOR = 293,
    OR = 294,
    LOGICAL_AND = 295,
    LOGICAL_OR = 296,
    QUESTION = 297,
    COLON = 298,
    EQUALS_MUL = 299,
    EQUALS_DIV = 300,
    EQUALS_MOD = 301,
    EQUALS_ADD = 302,
    EQUALS_SUB = 303,
    EQUALS_LSHIFT = 304,
    EQUALS_RSHIFT = 305,
    EQUALS_AND = 306,
    EQUALS_XOR = 307,
    EQUALS_OR = 308,
    TYPEDEF = 309,
    EXTERN = 310,
    STATIC = 311,
    AUTO = 312,
    REGISTER = 313,
    VOID = 314,
    CHAR = 315,
    SHORT = 316,
    INT = 317,
    LONG = 318,
    FLOAT = 319,
    DOUBLE = 320,
    SIGNED = 321,
    UNSIGNED = 322,
    STRUCT = 323,
    UNION = 324,
    ENUM = 325,
    CONST = 326,
    VOLATILE = 327,
    ELLIPSIS = 328,
    CASE = 329,
    DEFAULT = 330,
    IF = 331,
    ELSE = 332,
    SWITCH = 333,
    WHILE = 334,
    DO = 335,
    FOR = 336,
    GOTO = 337,
    CONTINUE = 338,
    BREAK = 339,
    RETURN = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "src/parser/parser.y" /* yacc.c:1909  */

        const Node* node;
        const expression* expr;
        const constant* cons;
        const declaration* decn;
        const declarator* decr;
        const specifier* decspec;
        const initial* init;
        const stat* statement;
        std::string* str;

#line 163 "src/parser/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_PARSER_TAB_HPP_INCLUDED  */
