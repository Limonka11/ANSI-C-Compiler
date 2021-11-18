%define parse.error verbose
%code requires{
        #include "parser.hpp"
        #include "lexer.hpp"

        extern const Node* root;

        extern FILE* yyin;
}

%union {
        const Node* node;
        const expression* expr;
        const constant* cons;
        const declaration* decn;
        const declarator* decr;
        const specifier* decspec;
        const initial* init;
        const stat* statement;
        std::string* str;
}

%token INT_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT IDENTIFIER STRING_LITERAL
%token SEMICOLON LBRACKET RBRACKET LCURLY RCURLY COMMA TILDE
%token EQUALS LSQUARE RSQUARE FULLSTOP ARROW INCREMENT DECREMENT
%token SIZEOF AMPERSAND ASTERISK PLUS MINUS EXCLAMATION FRONTSLASH
%token LSHIFT RSHIFT PERCENT
%token LESS GREATER LESS_EQUAL GREATER_EQUAL
%token EQUAL_EQUAL NOT_EQUAL
%token XOR OR LOGICAL_AND LOGICAL_OR
%token QUESTION COLON
%token EQUALS_MUL EQUALS_DIV EQUALS_MOD EQUALS_ADD EQUALS_SUB
%token EQUALS_LSHIFT EQUALS_RSHIFT EQUALS_AND EQUALS_XOR EQUALS_OR
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token STRUCT UNION ENUM CONST VOLATILE
%token ELLIPSIS
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR
%token GOTO CONTINUE BREAK RETURN

%right "then" ELSE

%type<node> ROOT TRANSLATION_UNIT FUNCTION_DEFINITION
EXTERNAL_DECLARATION DECLARATION PARAMETER_LIST
PARAMETER_TYPE_LIST PARAMETER_DECLARATION STATEMENT_LIST COMPOUND_STATEMENT
STATEMENT DECLARATION_LIST SELECTION_STATEMENT IDENTIFIER_LIST
TYPE_NAME

%type<expr> PRIMARY_EXPRESSION POSTFIX_EXPRESSION UNARY_EXPRESSION
CAST_EXPRESSION ADDITIVE_EXPRESSION SHIFT_EXPRESSION RELATIONAL_EXPRESSION
EQUALITY_EXPRESSION AND_EXPRESSION CONSTANT_EXPRESSION EXCLUSIVE_OR_EXPRESSION
INCLUSIVE_OR_EXPRESSION LOGICAL_AND_EXPRESSION LOGICAL_OR_EXPRESSION
MULTIPLICATIVE_EXPRESSION CONDITIONAL_EXPRESSION ASSIGNMENT_EXPRESSION
EXPRESSION ARGUMENT_EXPRESSION_LIST

%type<decr> DIRECT_DECLARATOR DECLARATOR INIT_DECLARATOR INIT_DECLARATOR_LIST

%type<decspec> TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST DECLARATION_SPECIFIERS

%type<cons> CONSTANT

%type<init> INITIALIZER

%type<statement> EXPRESSION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT

%type<str> IDENTIFIER INT_CONSTANT STRING_LITERAL
                        
%%

ROOT : TRANSLATION_UNIT { root = $$; }
        ;
        
PRIMARY_EXPRESSION : IDENTIFIER { $$ = new identifier($1); }
                   | CONSTANT { $$ = $1; }
//                   | STRING_LITERAL
                   | LBRACKET EXPRESSION RBRACKET { $$ = $2; }
                ;

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION { $$ = $1; }
                   | POSTFIX_EXPRESSION LSQUARE EXPRESSION RSQUARE { $$ = new voidExpr(); }
                   | POSTFIX_EXPRESSION LBRACKET RBRACKET { $$ = new functionCall($1); }
                   | POSTFIX_EXPRESSION LBRACKET ARGUMENT_EXPRESSION_LIST RBRACKET { $$ = new functionCallParams($1, $3); }
                   | POSTFIX_EXPRESSION FULLSTOP IDENTIFIER { $$ = new voidExpr(); }
                   | POSTFIX_EXPRESSION ARROW IDENTIFIER { $$ = new voidExpr(); }
                   | POSTFIX_EXPRESSION INCREMENT { $$ = new voidExpr(); }
                   | POSTFIX_EXPRESSION DECREMENT { $$ = new voidExpr(); }
                ;

ARGUMENT_EXPRESSION_LIST : ASSIGNMENT_EXPRESSION { $$ = $1; }
                         | ARGUMENT_EXPRESSION_LIST COMMA ASSIGNMENT_EXPRESSION { $$ = new argExprList($1, $3); }
                        ;
                        
UNARY_EXPRESSION : POSTFIX_EXPRESSION { $$ = $1; }
                 | INCREMENT UNARY_EXPRESSION { $$ = new voidExpr(); }
                 | DECREMENT UNARY_EXPRESSION { $$ = new voidExpr(); }
                 | SIZEOF UNARY_EXPRESSION { $$ = new voidExpr(); }
                 | SIZEOF LBRACKET TYPE_NAME RBRACKET { $$ = new voidExpr(); }
                 | MINUS CAST_EXPRESSION { $$ = new negation($2); }
                 | PLUS CAST_EXPRESSION { $$ = new positive($2); }
                 | EXCLAMATION CAST_EXPRESSION { $$ = new scalarNot($2); }
                 | TILDE CAST_EXPRESSION { $$ = new bitNot($2); }
                ;

CAST_EXPRESSION : UNARY_EXPRESSION { $$ = $1; }
                | LBRACKET TYPE_NAME RBRACKET CAST_EXPRESSION { $$ = new voidExpr(); }
                ;

MULTIPLICATIVE_EXPRESSION : CAST_EXPRESSION { $$ = $1; }
                          | MULTIPLICATIVE_EXPRESSION ASTERISK CAST_EXPRESSION { $$ = new mult_Expr($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION FRONTSLASH CAST_EXPRESSION { $$ = new div_Expr($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION PERCENT CAST_EXPRESSION { $$ = new mod_Expr($1, $3); }
                        ;

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION { $$ = $1; }
                    | ADDITIVE_EXPRESSION PLUS MULTIPLICATIVE_EXPRESSION { $$ = new add_Expr($1, $3); }
                    | ADDITIVE_EXPRESSION MINUS MULTIPLICATIVE_EXPRESSION { $$ = new sub_Expr($1, $3); }
                ;

SHIFT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1; }
                 | SHIFT_EXPRESSION LSHIFT ADDITIVE_EXPRESSION { $$ = new left_shift($1, $3); }
                 | SHIFT_EXPRESSION RSHIFT ADDITIVE_EXPRESSION { $$ = new right_shift($1, $3); }
                ;

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION { $$ = $1; }
                      | RELATIONAL_EXPRESSION LESS SHIFT_EXPRESSION { $$ = new lessThanExpr($1, $3); }
                      | RELATIONAL_EXPRESSION GREATER SHIFT_EXPRESSION { $$ = new greaterThanExpr($1, $3); }
                      | RELATIONAL_EXPRESSION LESS_EQUAL SHIFT_EXPRESSION { $$ = new lessEqualExpr($1, $3); }
                      | RELATIONAL_EXPRESSION GREATER_EQUAL SHIFT_EXPRESSION { $$ = new greaterEqualExpr($1, $3); }
                        ;

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION { $$ = $1; }
                    | EQUALITY_EXPRESSION EQUAL_EQUAL RELATIONAL_EXPRESSION { $$ = new equalToExpr($1, $3); }
                    | EQUALITY_EXPRESSION NOT_EQUAL RELATIONAL_EXPRESSION { $$ = new notEqualToExpr($1, $3); }
                        ;

AND_EXPRESSION : EQUALITY_EXPRESSION { $$ = $1; }
               | AND_EXPRESSION AMPERSAND EQUALITY_EXPRESSION { $$ = new andExpr($1, $3); }
                ;

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION { $$ = $1; }
                        | EXCLUSIVE_OR_EXPRESSION XOR AND_EXPRESSION { $$ = new xorExpr($1, $3); }
                        ;

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION { $$ = $1; }
                        | INCLUSIVE_OR_EXPRESSION OR EXCLUSIVE_OR_EXPRESSION { $$ = new orExpr($1, $3); }
                        ;

LOGICAL_AND_EXPRESSION : INCLUSIVE_OR_EXPRESSION { $$ = $1; }
                       | LOGICAL_AND_EXPRESSION LOGICAL_AND INCLUSIVE_OR_EXPRESSION { $$ = new logAnd($1, $3); }
                        ;

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION { $$ = $1; }
                      | LOGICAL_OR_EXPRESSION LOGICAL_OR LOGICAL_AND_EXPRESSION { $$ = new logOr($1, $3); }
                        ;

CONDITIONAL_EXPRESSION : LOGICAL_OR_EXPRESSION { $$ = $1; }
                       | LOGICAL_OR_EXPRESSION QUESTION EXPRESSION COLON CONDITIONAL_EXPRESSION { $$ = new voidExpr(); }
                        ;

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION { $$ = $1; }
                      | UNARY_EXPRESSION EQUALS ASSIGNMENT_EXPRESSION { $$ = new regularAssign($1, $3); }
                      | UNARY_EXPRESSION EQUALS_MUL ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } 
                      | UNARY_EXPRESSION EQUALS_DIV ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                      | UNARY_EXPRESSION EQUALS_MOD ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                      | UNARY_EXPRESSION EQUALS_ADD ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                      | UNARY_EXPRESSION EQUALS_SUB ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } 
                      | UNARY_EXPRESSION EQUALS_LSHIFT ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } 
                      | UNARY_EXPRESSION EQUALS_RSHIFT ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } 
                      | UNARY_EXPRESSION EQUALS_AND ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                      | UNARY_EXPRESSION EQUALS_XOR ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } 
                      | UNARY_EXPRESSION EQUALS_OR ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                        ;

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1; }
           | EXPRESSION COMMA ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }
                ;

CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION { $$ = $1; }
                        ;

DECLARATION : DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST SEMICOLON { $$ = new declaration($1, $2); }
            | DECLARATION_SPECIFIERS SEMICOLON { $$ = new voidDecl(); }
                ;

DECLARATION_SPECIFIERS : TYPE_SPECIFIER { $$ = $1; }
                       | TYPE_SPECIFIER DECLARATION_SPECIFIERS { $$ = new specList($1, $2); }
//                       | STORAGE_CLASS_SPECIFIER 
//                       | STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIERS
//                       | TYPE_QUALIFIER 
//                       | TYPE_QUALIFIER DECLARATION_SPECIFIERS
                        ;

INIT_DECLARATOR_LIST : INIT_DECLARATOR { $$ = $1; }
                     | INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR { $$ = new declaratorList($1, $3); }
                        ;

INIT_DECLARATOR : DECLARATOR { $$ = $1; }
                | DECLARATOR EQUALS INITIALIZER { $$ = new initDeclarator($1, $3); }
                ;

//STORAGE_CLASS_SPECIFIER : TYPEDEF
//                        | EXTERN
//                        | STATIC
//                        | AUTO
//                        | REGISTER
                        ;

TYPE_SPECIFIER : INT { $$ = new int_t(); }
//               | CHAR
//               | SHORT
               | VOID { $$ = new void_t(); }
//               | LONG
//               | FLOAT
//               | DOUBLE
//               | SIGNED
//               | UNSIGNED
                ;

//STRUCT_OR_UNION_SPECIFIER : STRUCT_OR_UNION IDENTIFIER 
//                          | STRUCT_OR_UNION LCURLY STRUCT_DECLARATION_LIST RCURLY 
//                          | STRUCT_OR_UNION IDENTIFIER LCURLY STRUCT_DECLARATION_LIST RCURLY 
                                ;

//STRUCT_OR_UNION : STRUCT
//                | UNION
                ;

//STRUCT_DECLARATION_LIST : STRUCT_DECLARATION 
//                        | STRUCT_DECLARATION_LIST STRUCT_DECLARATION 
                        ;

//STRUCT_DECLARATION : SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST SEMICOLON
                        ;

SPECIFIER_QUALIFIER_LIST : TYPE_SPECIFIER { $$ = $1; }
//                         | TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST 
//                         | TYPE_QUALIFIER // Just a type qualifier
//                         | TYPE_QUALIFIER SPECIFIER_QUALIFIER_LIST 
                                ;

//STRUCT_DECLARATOR_LIST : STRUCT_DECLARATOR 
//                       | STRUCT_DECLARATOR_LIST COMMA STRUCT_DECLARATOR 
                        ;

//STRUCT_DECLARATOR : DECLARATOR
//                  | COLON CONSTANT_EXPRESSION
//                  | DECLARATOR COLON CONSTANT_EXPRESSION
                        ;

//ENUM_SPECIFIER : ENUM LCURLY ENUMERATOR_LIST RCURLY 
//               | ENUM IDENTIFIER LCURLY ENUMERATOR_LIST RCURLY 
//               | ENUM IDENTIFIER 
                ;

//ENUMERATOR_LIST : ENUMERATOR 
//                | ENUMERATOR_LIST COMMA ENUMERATOR 
                ;
                
//ENUMERATOR : IDENTIFIER 
//           | IDENTIFIER EQUALS CONSTANT_EXPRESSION 
                ;

//TYPE_QUALIFIER : CONST
//               | VOLATILE
                ;

DECLARATOR : DIRECT_DECLARATOR { $$ = $1; }
//           | POINTER DIRECT_DECLARATOR
                ;

DIRECT_DECLARATOR : IDENTIFIER { $$ = new varDeclarator($1); }
//                | LBRACKET DECLARATOR RBRACKET
//                | DIRECT_DECLARATOR LSQUARE RSQUARE
                | DIRECT_DECLARATOR LSQUARE CONSTANT_EXPRESSION RSQUARE { $$ = new arrayDecl($1, $3); }
                  | DIRECT_DECLARATOR LBRACKET PARAMETER_TYPE_LIST RBRACKET { $$ = new funcDeclParam($1, $3); }
                  | DIRECT_DECLARATOR LBRACKET RBRACKET { $$ = new funcDecl($1); }
                  | DIRECT_DECLARATOR LBRACKET IDENTIFIER_LIST RBRACKET { $$ = new funcDeclParam($1, $3); }
                ;

//POINTER : ASTERISK // Pointer
//        | ASTERISK TYPE_QUALIFIER_LIST
//        | ASTERISK POINTER
//        | ASTERISK TYPE_QUALIFIER_LIST POINTER 
                ;

//TYPE_QUALIFIER_LIST : TYPE_QUALIFIER 
//                    | TYPE_QUALIFIER_LIST TYPE_QUALIFIER 
                        ;

PARAMETER_TYPE_LIST : PARAMETER_LIST { $$ = $1; };
                    | PARAMETER_LIST COMMA ELLIPSIS
                        ;

PARAMETER_LIST : PARAMETER_DECLARATION { $$ = $1; }
               | PARAMETER_LIST COMMA PARAMETER_DECLARATION { $$ = new paramList($1, $3); }
                ;

PARAMETER_DECLARATION : DECLARATION_SPECIFIERS DECLARATOR { $$ = new param($1, $2); }
//                      | DECLARATION_SPECIFIERS 
//                      | DECLARATION_SPECIFIERS ABSTRACT_DECLARATOR 
                        ;

IDENTIFIER_LIST : IDENTIFIER { $$ = new param(new varDeclarator($1)); }
                | IDENTIFIER_LIST COMMA IDENTIFIER { $$ = new paramList($1, new param(new varDeclarator($3))); }
                ;

TYPE_NAME : SPECIFIER_QUALIFIER_LIST { $$ = $1; }
//          | SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR 
                ;

//ABSTRACT_DECLARATOR : POINTER 
//                    | DIRECT_ABSTRACT_DECLARATOR
//                    | POINTER DIRECT_ABSTRACT_DECLARATOR
                        ;

//DIRECT_ABSTRACT_DECLARATOR : LBRACKET ABSTRACT_DECLARATOR RBRACKET 
//                           | LSQUARE RSQUARE 
//                           | LSQUARE CONSTANT_EXPRESSION RSQUARE 
//                           | DIRECT_ABSTRACT_DECLARATOR LSQUARE RSQUARE 
//                           | DIRECT_ABSTRACT_DECLARATOR LSQUARE CONSTANT_EXPRESSION RSQUARE 
//                           | LBRACKET RBRACKET 
//                           | LBRACKET PARAMETER_TYPE_LIST RBRACKET 
//                           | DIRECT_ABSTRACT_DECLARATOR LBRACKET RBRACKET 
//                           | DIRECT_ABSTRACT_DECLARATOR LBRACKET PARAMETER_TYPE_LIST RBRACKET 
                                ;

INITIALIZER : ASSIGNMENT_EXPRESSION { $$ = new initializerExpr($1); }
//            | LCURLY INITIALIZER_LIST RCURLY 
//            | LCURLY INITIALIZER_LIST COMMA RCURLY 
                ;

// INITIALIZER_LIST : INITIALIZER 
//                 | INITIALIZER_LIST COMMA INITIALIZER 
                ;

STATEMENT : COMPOUND_STATEMENT { $$ = $1; }
          | EXPRESSION_STATEMENT { $$ = $1; }
//          | LABELED_STATEMENT
          | SELECTION_STATEMENT { $$ = $1; }
          | ITERATION_STATEMENT { $$ = $1; }
          | JUMP_STATEMENT { $$ = $1; }
        ;

//LABELED_STATEMENT : IDENTIFIER COLON STATEMENT
//                  | CASE CONSTANT_EXPRESSION COLON STATEMENT
//                  | DEFAULT COLON STATEMENT
                        ;

COMPOUND_STATEMENT : LCURLY RCURLY { $$ = new emptyStat(); }
                   | LCURLY DECLARATION_LIST RCURLY { $$ = new decls($2); }
                   | LCURLY STATEMENT_LIST RCURLY { $$ = new stats($2); }
                   | LCURLY DECLARATION_LIST STATEMENT_LIST RCURLY { $$ = new decsStats($2, $3); }
                        ;

DECLARATION_LIST : DECLARATION { $$ = $1; }
                 | DECLARATION_LIST DECLARATION { $$ = new declarationList($1, $2); }
                ;

STATEMENT_LIST : STATEMENT { $$ = $1; }
               | STATEMENT_LIST STATEMENT { $$ = new statList($1, $2); }
                ;

EXPRESSION_STATEMENT : SEMICOLON { $$ = new emptyStat(); }
                     | EXPRESSION SEMICOLON { $$ = new exprStat($1); }
                        ;

SELECTION_STATEMENT : IF LBRACKET EXPRESSION RBRACKET STATEMENT %prec "then" { $$ = new ifStat($3, $5); }
                    | IF LBRACKET EXPRESSION RBRACKET STATEMENT ELSE STATEMENT { $$ = new ifStatElse($3, $5, $7); }
//                    | SWITCH LBRACKET EXPRESSION RBRACKET STATEMENT 
                        ;

ITERATION_STATEMENT : WHILE LBRACKET EXPRESSION RBRACKET STATEMENT { $$ = new whileLoop($3, $5); }
//                    | DO STATEMENT WHILE LBRACKET EXPRESSION RBRACKET SEMICOLON 
                    | FOR LBRACKET SEMICOLON SEMICOLON RBRACKET STATEMENT { $$ = new forLoop(new voidExpr(), new int_const(new std::string("1")), new voidExpr(), $6); }
                    | FOR LBRACKET EXPRESSION SEMICOLON SEMICOLON RBRACKET STATEMENT { $$ = new forLoop($3, new int_const(new std::string("1")), new voidExpr(), $7); }
                    | FOR LBRACKET SEMICOLON EXPRESSION SEMICOLON RBRACKET STATEMENT { $$ = new forLoop(new voidExpr(), $4, new voidExpr(), $7); }
                    | FOR LBRACKET SEMICOLON SEMICOLON EXPRESSION RBRACKET STATEMENT { $$ = new forLoop(new voidExpr(), new int_const(new std::string("1")), $5, $7); }
                    | FOR LBRACKET EXPRESSION SEMICOLON EXPRESSION SEMICOLON RBRACKET STATEMENT { $$ = new forLoop($3, $5, new voidExpr(), $8); }
                    | FOR LBRACKET SEMICOLON EXPRESSION SEMICOLON EXPRESSION RBRACKET STATEMENT { $$ = new forLoop(new voidExpr(), $4, $6, $8); }
                    | FOR LBRACKET EXPRESSION SEMICOLON SEMICOLON EXPRESSION RBRACKET STATEMENT { $$ = new forLoop($3, new int_const(new std::string("1")), $6, $8); }
                    | FOR LBRACKET EXPRESSION SEMICOLON EXPRESSION SEMICOLON EXPRESSION RBRACKET STATEMENT { $$ = new forLoop($3, $5, $7, $9); }
                        ;

JUMP_STATEMENT : RETURN SEMICOLON { $$ = new returnStat(new voidExpr()); }
               | RETURN EXPRESSION SEMICOLON { $$ = new returnStat($2); }
//               | GOTO IDENTIFIER SEMICOLON
//               | CONTINUE SEMICOLON { $$ = new loopContinue(); }
               | BREAK SEMICOLON { $$ = new loopBreak(); }
                ;

TRANSLATION_UNIT : EXTERNAL_DECLARATION { $$ = $1; }
                 | EXTERNAL_DECLARATION TRANSLATION_UNIT { $$ = new translationUnit($1, $2); }
                ;

EXTERNAL_DECLARATION : DECLARATION { $$ = $1; }
                     | FUNCTION_DEFINITION { $$ = $1; }
                        ;

FUNCTION_DEFINITION : DECLARATION_SPECIFIERS DECLARATOR COMPOUND_STATEMENT { $$ = new funcDef($1, $2, $3); }
                    | DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT { $$ = new funcDefDeclList(new int_t(), $1, $2, $3); }
                    | DECLARATOR COMPOUND_STATEMENT { $$ = new funcDef(new int_t(), $1, $2); }
                    | DECLARATION_SPECIFIERS DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT { $$ = new funcDefDeclList($1, $2, $3, $4); }
                ;

CONSTANT : INT_CONSTANT { $$ = new int_const($1); }
         //| FLOAT_CONSTANT
         //| CHAR_CONSTANT


%%
const Node* root;

const Node* parse(std::string src)
{

        const char* c = src.c_str();
        yyin = fopen(c, "r");

        root = NULL;

        if(yyin)
        {
                yyparse();
        }
        //yyparse(fp);
        //yyparse();
        fclose(yyin);
        return root;
}
