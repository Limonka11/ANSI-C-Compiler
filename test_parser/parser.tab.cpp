/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "parser.y" /* yacc.c:355  */

        #include "parser.hpp"
        #include "lexer.hpp"

        extern const Node* root;

#line 104 "parser.tab.cpp" /* yacc.c:355  */

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
#line 8 "parser.y" /* yacc.c:355  */

        const Node* node;
        const expression* expr;
        const constant* cons;
        const declaration* decn;
        const declarator* decr;
        const declarationSpec* decspec;
        const initializer* init;
        const statement* stat;
        std::string* str;

#line 214 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    72,    73,    74,    75,    77,    78,    79,
      80,    81,    82,    83,    84,    86,    87,    89,    90,    91,
      92,    93,    94,    96,    97,    98,    99,   100,   101,   103,
     104,   106,   107,   108,   109,   111,   112,   113,   115,   116,
     117,   119,   120,   121,   122,   123,   125,   126,   127,   129,
     130,   132,   133,   135,   136,   138,   139,   141,   142,   144,
     145,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   160,   161,   165,   166,   168,   169,   175,
     176,   178,   179,   187,   211,   236,   239,   243,   244,   245,
     255,   256,   258,   259,   261,   265,   266,   268,   286,   293,
     294,   296,   297,   298,   304,   305,   306,   307,   309,   310,
     312,   313,   315,   316,   318,   319,   322,   333,   334,   339,
     340,   342,   343,   345,   346,   347,   348,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT_CONSTANT", "T_CHAR_CONSTANT",
  "T_FLOAT_CONSTANT", "T_IDENTIFIER", "T_STRING_LITERAL", "T_SEMICOLON",
  "T_LBRACKET", "T_RBRACKET", "T_LCURLY", "T_RCURLY", "T_COMMA", "T_TILDE",
  "T_EQUALS", "T_LSQUARE", "T_RSQUARE", "T_FULLSTOP", "T_ARROW",
  "T_INCREMENT", "T_DECREMENT", "T_SIZEOF", "T_AMPERSAND", "T_ASTERISK",
  "T_PLUS", "T_MINUS", "T_EXCLAMATION", "T_FRONTSLASH", "T_LSHIFT",
  "T_RSHIFT", "T_PERCENT", "T_LESS", "T_GREATER", "T_LESS_EQUAL",
  "T_GREATER_EQUAL", "T_EQUAL_EQUAL", "T_NOT_EQUAL", "T_XOR", "T_OR",
  "T_LOGICAL_AND", "T_LOGICAL_OR", "T_QUESTION", "T_COLON", "T_EQUALS_MUL",
  "T_EQUALS_DIV", "T_EQUALS_MOD", "T_EQUALS_ADD", "T_EQUALS_SUB",
  "T_EQUALS_LSHIFT", "T_EQUALS_RSHIFT", "T_EQUALS_AND", "T_EQUALS_XOR",
  "T_EQUALS_OR", "T_TYPEDEF", "T_EXTERN", "T_STATIC", "T_AUTO",
  "T_REGISTER", "T_VOID", "T_CHAR", "T_SHORT", "T_INT", "T_LONG",
  "T_FLOAT", "T_DOUBLE", "T_SIGNED", "T_UNSIGNED", "T_STRUCT", "T_UNION",
  "T_ENUM", "T_CONST", "T_VOLATILE", "T_ELLIPSIS", "T_CASE", "T_DEFAULT",
  "T_IF", "T_ELSE", "T_SWITCH", "T_WHILE", "T_DO", "T_FOR", "T_GOTO",
  "T_CONTINUE", "T_BREAK", "T_RETURN", "\"then\"", "$accept", "ROOT",
  "PRIMARY_EXPRESSION", "POSTFIX_EXPRESSION", "ARGUMENT_EXPRESSION_LIST",
  "UNARY_EXPRESSION", "UNARY_OPERATOR", "CAST_EXPRESSION",
  "MULTIPLICATIVE_EXPRESSION", "ADDITIVE_EXPRESSION", "SHIFT_EXPRESSION",
  "RELATIONAL_EXPRESSION", "EQUALITY_EXPRESSION", "AND_EXPRESSION",
  "EXCLUSIVE_OR_EXPRESSION", "INCLUSIVE_OR_EXPRESSION",
  "LOGICAL_AND_EXPRESSION", "LOGICAL_OR_EXPRESSION",
  "CONDITIONAL_EXPRESSION", "ASSIGNMENT_EXPRESSION", "EXPRESSION",
  "DECLARATION", "DECLARATION_SPECIFIERS", "INIT_DECLARATOR_LIST",
  "INIT_DECLARATOR", "TYPE_SPECIFIER", "SPECIFIER_QUALIFIER_LIST",
  "DECLARATOR", "DIRECT_DECLARATOR", "PARAMETER_TYPE_LIST",
  "PARAMETER_LIST", "PARAMETER_DECLARATION", "IDENTIFIER_LIST",
  "TYPE_NAME", "INITIALIZER", "STATEMENT", "COMPOUND_STATEMENT",
  "DECLARATION_LIST", "STATEMENT_LIST", "EXPRESSION_STATEMENT",
  "SELECTION_STATEMENT", "ITERATION_STATEMENT", "JUMP_STATEMENT",
  "TRANSLATION_UNIT", "EXTERNAL_DECLARATION", "FUNCTION_DEFINITION",
  "CONSTANT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,   -67,   -67,    13,   -67,    44,    18,    -5,    26,   -67,
      -2,   -67,   -67,   -67,    38,   -67,     9,   -67,   140,   -67,
      44,   -67,    -5,     8,   -67,   -67,    86,   389,   -67,    -5,
     -67,   -67,   -67,   -67,   304,   -67,   -67,   414,   414,   439,
     -67,   -67,   -67,   -67,   -67,   102,   112,   338,   -67,    12,
      -8,   389,   -67,    30,    39,   139,    96,   134,   109,    81,
      98,   117,   131,   -67,   -67,    55,   -67,   -67,   172,   206,
     -67,   -67,   -67,   -67,   -67,   144,   -67,   -67,   -67,   -67,
      86,   164,   169,   -67,    16,   -67,   -67,   -67,   -67,   103,
     -67,   -67,   175,   389,   -67,   -67,   304,   -67,   389,   389,
     -67,    59,   364,   389,   183,   197,   -67,   -67,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   -67,
     -67,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     -67,   389,   -67,   238,   -67,   -67,   -67,   -67,   -14,   -67,
     198,   -67,   389,   195,   110,   123,   -67,   -67,   132,   -67,
      61,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,    30,    30,    39,
      39,   139,   139,   139,   139,    96,    96,   134,   109,    81,
      98,   117,     6,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     272,   272,   -67,   389,   -67,   389,   129,   -67,   -67,   -67,
     272,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    83,     0,   121,     0,    77,     0,    85,     2,
     119,   122,     1,    76,     0,    79,    81,    78,     0,   108,
       0,   125,     0,     0,   120,    75,     0,     0,   123,     0,
     127,     3,     5,   112,     0,   104,    27,     0,     0,     0,
      23,    24,    25,    26,    28,     0,     0,     0,     7,    17,
      29,     0,    31,    35,    38,    41,    46,    49,    51,    53,
      55,    57,    59,    61,    73,     0,   110,    99,     0,     0,
     100,   101,   102,   103,     4,    81,   109,   124,    95,    88,
       0,     0,    90,    92,     0,    80,    98,    82,   126,     0,
      84,    97,     0,     0,    18,    19,     0,    21,     0,     0,
     117,     0,     0,     0,     0,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,   105,     0,   106,   111,    94,    87,     0,    89,
       0,     6,     0,     0,     0,     0,   118,     9,     0,    15,
       0,    11,    12,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    32,    33,    34,    36,    37,    39,
      40,    42,    43,    44,    45,    47,    48,    50,    52,    54,
      56,    58,     0,    74,   107,    91,    93,    96,    30,    22,
       0,     0,    10,     0,     8,     0,   114,   116,    16,    60,
       0,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -28,   -67,     4,    63,    64,
      10,    68,    73,    75,    72,    74,    83,   -67,    17,   -27,
      19,     5,     2,   -67,   209,   -17,   -67,    -4,   -67,   -67,
     -67,    76,   -67,   127,   -67,   -66,    40,   137,   168,   -67,
     -67,   -67,   -67,   227,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    48,    49,   158,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    19,    20,    14,    15,     6,    91,     7,     8,    81,
      82,    83,    84,    92,    87,    66,    67,    22,    69,    70,
      71,    72,    73,     9,    10,    11,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    16,     5,   145,     1,     4,    18,   108,    17,    94,
      95,    97,     5,    12,    78,     4,    75,    90,    79,   141,
      18,   102,    75,   119,    27,    80,   149,    76,   103,   150,
     104,   105,   106,   107,    76,    23,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    25,    21,     2,   205,
       1,    26,    13,    89,   121,   120,    28,     2,   122,   195,
       2,   123,    77,   140,   124,   125,   101,   156,   141,    88,
       2,     2,   141,    76,   141,   159,   146,   145,   204,    90,
       2,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     1,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,    98,    89,   151,   193,    89,   141,   154,   155,   135,
     200,    99,   160,   141,   119,   174,   175,   176,   128,   129,
     130,   131,   134,   201,   206,   207,   141,   136,   181,   182,
     183,   184,   202,    30,   211,   203,    31,    32,    33,    34,
      80,    18,    35,    29,    36,    68,   198,   137,   192,    27,
      37,    38,    39,    40,    41,    42,    43,    44,   126,   127,
     132,   133,   138,   139,   147,    30,   208,   119,    31,    32,
      33,    34,   148,    18,   142,   152,    36,   177,   178,   161,
     179,   180,    37,    38,    39,    40,    41,    42,    43,    44,
     185,   186,     2,   162,   197,   199,   210,   187,   189,    30,
     188,   190,    31,    32,    33,    34,    45,    18,   144,    46,
      36,   191,   209,   153,   196,    47,    37,    38,    39,    40,
      41,    42,    43,    44,     2,    85,   143,    24,     0,     0,
       0,    30,     0,     0,    31,    32,    33,    34,    45,    18,
     194,    46,    36,     0,     0,     0,     0,    47,    37,    38,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    31,    32,
      33,    34,    45,    18,     0,    46,    36,     0,     0,     0,
       0,    47,    37,    38,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
      31,    32,     0,    34,    45,     0,     0,    46,    36,     0,
       0,     0,     0,    47,    37,    38,    39,    40,    41,    42,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,    31,    32,   100,    34,    45,     0,
       0,    46,    36,     0,     0,     0,     0,    47,    37,    38,
      39,    40,    41,    42,    43,    44,     2,    30,     0,     0,
      31,    32,     0,    34,   157,     0,     0,     0,    36,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    30,     0,     0,    31,    32,     0,    34,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    30,     0,     0,
      31,    32,     0,    93,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    30,     0,     0,    31,    32,     0,    96,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      27,     5,     0,    69,     6,     0,    11,    15,     6,    37,
      38,    39,    10,     0,     6,    10,    20,    34,    10,    13,
      11,     9,    26,    51,    15,    23,    10,    22,    16,    13,
      18,    19,    20,    21,    29,     9,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     8,     7,    62,    43,
       6,    13,     8,    34,    24,    51,    16,    62,    28,    73,
      62,    31,    22,     8,    25,    26,    47,     8,    13,    29,
      62,    62,    13,    68,    13,   102,    80,   143,    17,    96,
      62,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     6,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     9,    93,    10,   141,    96,    13,    98,    99,    38,
      10,     9,   103,    13,   152,   121,   122,   123,    32,    33,
      34,    35,    23,    10,   200,   201,    13,    39,   128,   129,
     130,   131,    10,     3,   210,    13,     6,     7,     8,     9,
     148,    11,    12,    16,    14,    18,   152,    40,   139,    15,
      20,    21,    22,    23,    24,    25,    26,    27,    29,    30,
      36,    37,    41,    42,    10,     3,   203,   205,     6,     7,
       8,     9,    13,    11,    12,    10,    14,   124,   125,     6,
     126,   127,    20,    21,    22,    23,    24,    25,    26,    27,
     132,   133,    62,     6,     6,    10,    77,   134,   136,     3,
     135,   137,     6,     7,     8,     9,    76,    11,    12,    79,
      14,   138,   205,    96,   148,    85,    20,    21,    22,    23,
      24,    25,    26,    27,    62,    26,    68,    10,    -1,    -1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    76,    11,
      12,    79,    14,    -1,    -1,    -1,    -1,    85,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,
       8,     9,    76,    11,    -1,    79,    14,    -1,    -1,    -1,
      -1,    85,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
       6,     7,    -1,     9,    76,    -1,    -1,    79,    14,    -1,
      -1,    -1,    -1,    85,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    76,    -1,
      -1,    79,    14,    -1,    -1,    -1,    -1,    85,    20,    21,
      22,    23,    24,    25,    26,    27,    62,     3,    -1,    -1,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,     3,    -1,    -1,     6,     7,    -1,     9,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,     3,    -1,    -1,
       6,     7,    -1,     9,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,     3,    -1,    -1,     6,     7,    -1,     9,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    62,    88,   108,   109,   112,   114,   115,   130,
     131,   132,     0,     8,   110,   111,   114,   109,    11,   108,
     109,   123,   124,     9,   130,     8,    13,    15,   123,   124,
       3,     6,     7,     8,     9,    12,    14,    20,    21,    22,
      23,    24,    25,    26,    27,    76,    79,    85,    89,    90,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   122,   123,   124,   125,
     126,   127,   128,   129,   133,   114,   108,   123,     6,    10,
     109,   116,   117,   118,   119,   111,   106,   121,   123,   107,
     112,   113,   120,     9,    92,    92,     9,    92,     9,     9,
       8,   107,     9,    16,    18,    19,    20,    21,    15,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    92,
      94,    24,    28,    31,    25,    26,    29,    30,    32,    33,
      34,    35,    36,    37,    23,    38,    39,    40,    41,    42,
       8,    13,    12,   125,    12,   122,   114,    10,    13,    10,
      13,    10,    10,   120,   107,   107,     8,    10,    91,   106,
     107,     6,     6,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    98,    99,   100,   101,
     102,   103,   107,   106,    12,    73,   118,     6,    94,    10,
      10,    10,    10,    13,    17,    43,   122,   122,   106,   105,
      77,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   113,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   119,   119,   120,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   132,   132,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     4,     3,     4,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     2,     3,     1,
       2,     1,     1,     3,     3,     2,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 70 "parser.y" /* yacc.c:1646  */
    { root = (yyval.node); }
#line 1543 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new identifier((yyvsp[0].str)); }
#line 1549 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].cons); }
#line 1555 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new string_constant((yyvsp[0].str)); }
#line 1561 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1567 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1573 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1579 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new functionCall((yyvsp[-2].expr)); }
#line 1585 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new functionCallParams((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1591 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1597 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1603 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1609 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1615 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 86 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1621 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new argumentExprList((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1627 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1633 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1639 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1645 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1651 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1657 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1663 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1669 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1675 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1681 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new multiplication_Expr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1687 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1693 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1699 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1705 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new addition_Expr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1711 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new subtraction_Expr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1717 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1723 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1729 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1735 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1741 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new lessThanExpr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1747 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1753 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1759 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1765 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1771 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new equalToExpr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1777 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1783 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1789 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1795 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1801 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1807 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1813 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1819 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1825 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1831 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1837 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1843 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1849 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1855 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1861 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new regularAssignment((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1867 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1873 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1879 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1885 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1891 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1897 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1903 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1909 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1915 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1921 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1927 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1933 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidExpr(); }
#line 1939 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration((yyvsp[-2].decspec), (yyvsp[-1].decr)); }
#line 1945 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new voidDeclaration(); }
#line 1951 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.decspec) = (yyvsp[0].decspec); }
#line 1957 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.decspec) = new declarationSpecList((yyvsp[-1].decspec), (yyvsp[0].decspec)); }
#line 1963 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = (yyvsp[0].decr); }
#line 1969 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new declaratorList((yyvsp[-2].decr), (yyvsp[0].decr)); }
#line 1975 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = (yyvsp[0].decr); }
#line 1981 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new initDeclarator((yyvsp[-2].decr), (yyvsp[0].init)); }
#line 1987 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.decspec) = new int_type(); }
#line 1993 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.decspec) = (yyvsp[0].decspec); }
#line 1999 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = (yyvsp[0].decr); }
#line 2005 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new varDeclarator((yyvsp[0].str)); }
#line 2011 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new functionDeclaratorParams((yyvsp[-3].decr), (yyvsp[-1].node)); }
#line 2017 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new functionDeclarator((yyvsp[-2].decr)); }
#line 2023 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.decr) = new functionDeclaratorParams((yyvsp[-3].decr), (yyvsp[-1].node)); }
#line 2029 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2035 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2041 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new paramList((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2047 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new paramDeclaration((yyvsp[-1].decspec), (yyvsp[0].decr)); }
#line 2053 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new paramDeclaration(new varDeclarator((yyvsp[0].str))); }
#line 2059 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new paramList((yyvsp[-2].node), new paramDeclaration(new varDeclarator((yyvsp[0].str)))); }
#line 2065 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].decspec); }
#line 2071 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.init) = new initializerExpr((yyvsp[0].expr)); }
#line 2077 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2083 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].stat); }
#line 2089 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2095 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].stat); }
#line 2101 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].stat); }
#line 2107 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new emptyStat(); }
#line 2113 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new compoundStatDecs((yyvsp[-1].node)); }
#line 2119 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new compoundStat((yyvsp[-1].node)); }
#line 2125 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new compoundStatDecsStats((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2131 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2137 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declarationList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2143 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2149 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new statList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2155 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new emptyStat(); }
#line 2161 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new expressionStat((yyvsp[-1].expr)); }
#line 2167 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new selectionStat((yyvsp[-2].expr), (yyvsp[0].node)); }
#line 2173 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new selectionStatElse((yyvsp[-4].expr), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2179 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new whileStat((yyvsp[-2].expr), (yyvsp[0].node)); }
#line 2185 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new returnStat(new voidExpr()); }
#line 2191 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new returnStat((yyvsp[-1].expr)); }
#line 2197 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2203 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new translationUnit((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2209 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2215 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2221 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new functionDef((yyvsp[-2].decspec), (yyvsp[-1].decr), (yyvsp[0].node)); }
#line 2227 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new functionDefDeclList(new int_type(), (yyvsp[-2].decr), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2233 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new functionDef(new int_type(), (yyvsp[-1].decr), (yyvsp[0].node)); }
#line 2239 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new functionDefDeclList((yyvsp[-3].decspec), (yyvsp[-2].decr), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2245 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.cons) = new int_constant((yyvsp[0].str)); }
#line 2251 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2255 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 355 "parser.y" /* yacc.c:1906  */

const Node* root; // Store the root of the AST
const Node* parse()
{
        root = NULL;
        yyparse();
        return root;
}
