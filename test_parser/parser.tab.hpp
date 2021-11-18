/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This coderam is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This coderam is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this coderam.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:1909  */

        #include "parser.hpp"
        #include "lexer.hpp"

        extern const Node* root;

#line 51 "parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT_CONSTANT = 258,
    T_CHAR_CONSTANT = 259,
    T_FLOAT_CONSTANT = 260,
    T_IDENTIFIER = 261,
    T_STRING_LITERAL = 262,
    T_SEMICOLON = 263,
    T_LBRACKET = 264,
    T_RBRACKET = 265,
    T_LCURLY = 266,
    T_RCURLY = 267,
    T_COMMA = 268,
    T_TILDE = 269,
    T_EQUALS = 270,
    T_LSQUARE = 271,
    T_RSQUARE = 272,
    T_FULLSTOP = 273,
    T_ARROW = 274,
    T_INCREMENT = 275,
    T_DECREMENT = 276,
    T_SIZEOF = 277,
    T_AMPERSAND = 278,
    T_ASTERISK = 279,
    T_PLUS = 280,
    T_MINUS = 281,
    T_EXCLAMATION = 282,
    T_FRONTSLASH = 283,
    T_LSHIFT = 284,
    T_RSHIFT = 285,
    T_PERCENT = 286,
    T_LESS = 287,
    T_GREATER = 288,
    T_LESS_EQUAL = 289,
    T_GREATER_EQUAL = 290,
    T_EQUAL_EQUAL = 291,
    T_NOT_EQUAL = 292,
    T_XOR = 293,
    T_OR = 294,
    T_LOGICAL_AND = 295,
    T_LOGICAL_OR = 296,
    T_QUESTION = 297,
    T_COLON = 298,
    T_EQUALS_MUL = 299,
    T_EQUALS_DIV = 300,
    T_EQUALS_MOD = 301,
    T_EQUALS_ADD = 302,
    T_EQUALS_SUB = 303,
    T_EQUALS_LSHIFT = 304,
    T_EQUALS_RSHIFT = 305,
    T_EQUALS_AND = 306,
    T_EQUALS_XOR = 307,
    T_EQUALS_OR = 308,
    T_TYPEDEF = 309,
    T_EXTERN = 310,
    T_STATIC = 311,
    T_AUTO = 312,
    T_REGISTER = 313,
    T_VOID = 314,
    T_CHAR = 315,
    T_SHORT = 316,
    T_INT = 317,
    T_LONG = 318,
    T_FLOAT = 319,
    T_DOUBLE = 320,
    T_SIGNED = 321,
    T_UNSIGNED = 322,
    T_STRUCT = 323,
    T_UNION = 324,
    T_ENUM = 325,
    T_CONST = 326,
    T_VOLATILE = 327,
    T_ELLIPSIS = 328,
    T_CASE = 329,
    T_DEFAULT = 330,
    T_IF = 331,
    T_ELSE = 332,
    T_SWITCH = 333,
    T_WHILE = 334,
    T_DO = 335,
    T_FOR = 336,
    T_GOTO = 337,
    T_CONTINUE = 338,
    T_BREAK = 339,
    T_RETURN = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "parser.y" /* yacc.c:1909  */

        const Node* node;
        const expression* expr;
        const constant* cons;
        const declaration* decn;
        const declarator* decr;
        const declarationSpec* decspec;
        const initializer* init;
        const statement* stat;
        std::string* str;

#line 161 "parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
