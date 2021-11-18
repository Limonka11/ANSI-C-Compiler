%code requires{
        #include "parser.hpp"
        #include "lexer.hpp"

        extern const Node* root;
}

%union {
        const Node* node;
        const expression* expr;
        const constant* cons;
        const declaration* decn;
        const declarator* decr;
        const declarationSpec* decspec;
        const initializer* init;
        const statement* stat;
        std::string* str;
}

// Terminal groupings
%token T_INT_CONSTANT T_CHAR_CONSTANT T_FLOAT_CONSTANT T_IDENTIFIER T_STRING_LITERAL
%token T_SEMICOLON T_LBRACKET T_RBRACKET T_LCURLY T_RCURLY T_COMMA T_TILDE
%token T_EQUALS T_LSQUARE T_RSQUARE T_FULLSTOP T_ARROW T_INCREMENT T_DECREMENT
%token T_SIZEOF T_AMPERSAND T_ASTERISK T_PLUS T_MINUS T_EXCLAMATION T_FRONTSLASH
%token T_LSHIFT T_RSHIFT T_PERCENT
%token T_LESS T_GREATER T_LESS_EQUAL T_GREATER_EQUAL
%token T_EQUAL_EQUAL T_NOT_EQUAL
%token T_XOR T_OR T_LOGICAL_AND T_LOGICAL_OR
%token T_QUESTION T_COLON
%token T_EQUALS_MUL T_EQUALS_DIV T_EQUALS_MOD T_EQUALS_ADD T_EQUALS_SUB
%token T_EQUALS_LSHIFT T_EQUALS_RSHIFT T_EQUALS_AND T_EQUALS_XOR T_EQUALS_OR
%token T_TYPEDEF T_EXTERN T_STATIC T_AUTO T_REGISTER
%token T_VOID T_CHAR T_SHORT T_INT T_LONG T_FLOAT T_DOUBLE T_SIGNED T_UNSIGNED
%token T_STRUCT T_UNION T_ENUM T_CONST T_VOLATILE
%token T_ELLIPSIS
%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_DO T_FOR
%token T_GOTO T_CONTINUE T_BREAK T_RETURN

// Choose closest if in "dangling else" problem
%right "then" T_ELSE

%type<node> ROOT TRANSLATION_UNIT FUNCTION_DEFINITION
EXTERNAL_DECLARATION DECLARATION PARAMETER_LIST
PARAMETER_TYPE_LIST PARAMETER_DECLARATION STATEMENT_LIST COMPOUND_STATEMENT
STATEMENT DECLARATION_LIST SELECTION_STATEMENT IDENTIFIER_LIST
TYPE_NAME

%type<expr> PRIMARY_EXPRESSION POSTFIX_EXPRESSION UNARY_EXPRESSION
CAST_EXPRESSION ADDITIVE_EXPRESSION SHIFT_EXPRESSION RELATIONAL_EXPRESSION
EQUALITY_EXPRESSION AND_EXPRESSION EXCLUSIVE_OR_EXPRESSION
INCLUSIVE_OR_EXPRESSION LOGICAL_AND_EXPRESSION LOGICAL_OR_EXPRESSION
MULTIPLICATIVE_EXPRESSION CONDITIONAL_EXPRESSION ASSIGNMENT_EXPRESSION
EXPRESSION ARGUMENT_EXPRESSION_LIST


%type<decr> DIRECT_DECLARATOR DECLARATOR INIT_DECLARATOR INIT_DECLARATOR_LIST

%type<decspec> TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST DECLARATION_SPECIFIERS

%type<cons> CONSTANT

%type<init> INITIALIZER

%type<stat> EXPRESSION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT

%type<str> T_IDENTIFIER T_INT_CONSTANT T_STRING_LITERAL
                        
%%

ROOT : TRANSLATION_UNIT { root = $$; }

PRIMARY_EXPRESSION : T_IDENTIFIER { $$ = new identifier($1); }
                   | CONSTANT { $$ = $1; }
                   | T_STRING_LITERAL { $$ = new string_constant($1); }
                   | T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2; }

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION { $$ = $1; }
                   | POSTFIX_EXPRESSION T_LSQUARE EXPRESSION T_RSQUARE { $$ = new voidExpr(); } // TEMPORARY
                   | POSTFIX_EXPRESSION T_LBRACKET T_RBRACKET { $$ = new functionCall($1); }
                   | POSTFIX_EXPRESSION T_LBRACKET ARGUMENT_EXPRESSION_LIST T_RBRACKET { $$ = new functionCallParams($1, $3); }
                   | POSTFIX_EXPRESSION T_FULLSTOP T_IDENTIFIER { $$ = new voidExpr(); } // TEMPORARY
                   | POSTFIX_EXPRESSION T_ARROW T_IDENTIFIER { $$ = new voidExpr(); } // TEMPORARY
                   | POSTFIX_EXPRESSION T_INCREMENT { $$ = new voidExpr(); } // TEMPORARY
                   | POSTFIX_EXPRESSION T_DECREMENT { $$ = new voidExpr(); } // TEMPORARY

ARGUMENT_EXPRESSION_LIST : ASSIGNMENT_EXPRESSION { $$ = $1; }
                         | ARGUMENT_EXPRESSION_LIST T_COMMA ASSIGNMENT_EXPRESSION { $$ = new argumentExprList($1, $3); }

UNARY_EXPRESSION : POSTFIX_EXPRESSION { $$ = $1; }
                 | T_INCREMENT UNARY_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                 | T_DECREMENT UNARY_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                 | UNARY_OPERATOR CAST_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                 | T_SIZEOF UNARY_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                 | T_SIZEOF T_LBRACKET TYPE_NAME T_RBRACKET { $$ = new voidExpr(); } // TEMPORARY

UNARY_OPERATOR : T_AMPERSAND
               | T_ASTERISK
               | T_PLUS
               | T_MINUS
               | T_TILDE
               | T_EXCLAMATION

CAST_EXPRESSION : UNARY_EXPRESSION { $$ = $1; }
                | T_LBRACKET TYPE_NAME T_RBRACKET CAST_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

MULTIPLICATIVE_EXPRESSION : CAST_EXPRESSION { $$ = $1; }
                          | MULTIPLICATIVE_EXPRESSION T_ASTERISK CAST_EXPRESSION { $$ = new multiplication_Expr($1, $3); } // TEMPORARY
                          | MULTIPLICATIVE_EXPRESSION T_FRONTSLASH CAST_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                          | MULTIPLICATIVE_EXPRESSION T_PERCENT CAST_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION { $$ = $1; }
                    | ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION { $$ = new addition_Expr($1, $3); }
                    | ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION { $$ = new subtraction_Expr($1, $3); }

SHIFT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1; }
                 | SHIFT_EXPRESSION T_LSHIFT ADDITIVE_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                 | SHIFT_EXPRESSION T_RSHIFT ADDITIVE_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION { $$ = $1; }
                      | RELATIONAL_EXPRESSION T_LESS SHIFT_EXPRESSION { $$ = new lessThanExpr($1, $3); } // TEMPORARY
                      | RELATIONAL_EXPRESSION T_GREATER SHIFT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | RELATIONAL_EXPRESSION T_LESS_EQUAL SHIFT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | RELATIONAL_EXPRESSION T_GREATER_EQUAL SHIFT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION { $$ = $1; }
                    | EQUALITY_EXPRESSION T_EQUAL_EQUAL RELATIONAL_EXPRESSION { $$ = new equalToExpr($1, $3); }
                    | EQUALITY_EXPRESSION T_NOT_EQUAL RELATIONAL_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

AND_EXPRESSION : EQUALITY_EXPRESSION { $$ = $1; }
               | AND_EXPRESSION T_AMPERSAND EQUALITY_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION { $$ = $1; }
                        | EXCLUSIVE_OR_EXPRESSION T_XOR AND_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION { $$ = $1; }
                        | INCLUSIVE_OR_EXPRESSION T_OR EXCLUSIVE_OR_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

LOGICAL_AND_EXPRESSION : INCLUSIVE_OR_EXPRESSION { $$ = $1; }
                       | LOGICAL_AND_EXPRESSION T_LOGICAL_AND INCLUSIVE_OR_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION { $$ = $1; }
                      | LOGICAL_OR_EXPRESSION T_LOGICAL_OR LOGICAL_AND_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

CONDITIONAL_EXPRESSION : LOGICAL_OR_EXPRESSION { $$ = $1; }
                       | LOGICAL_OR_EXPRESSION T_QUESTION EXPRESSION T_COLON CONDITIONAL_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION { $$ = $1; }
                      | UNARY_EXPRESSION T_EQUALS ASSIGNMENT_EXPRESSION { $$ = new regularAssignment($1, $3); }
                      | UNARY_EXPRESSION T_EQUALS_MUL ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_DIV ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_MOD ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_ADD ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_SUB ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_LSHIFT ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_RSHIFT ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_AND ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_XOR ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY
                      | UNARY_EXPRESSION T_EQUALS_OR ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); } // TEMPORARY

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1; }
           | EXPRESSION T_COMMA ASSIGNMENT_EXPRESSION { $$ = new voidExpr(); }

//CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION

DECLARATION : DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST T_SEMICOLON { $$ = new declaration($1, $2); }
            | DECLARATION_SPECIFIERS T_SEMICOLON { $$ = new voidDeclaration(); }

DECLARATION_SPECIFIERS : TYPE_SPECIFIER { $$ = $1; }
                       | TYPE_SPECIFIER DECLARATION_SPECIFIERS { $$ = new declarationSpecList($1, $2); }
//                       | STORAGE_CLASS_SPECIFIER // Declaration of just storage class
//                       | STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIERS // Declaration of storage class and more
//                       | TYPE_QUALIFIER // Declaration of just type qualifier
//                       | TYPE_QUALIFIER DECLARATION_SPECIFIERS // Declaration of qualifier and more

INIT_DECLARATOR_LIST : INIT_DECLARATOR { $$ = $1; }
                     | INIT_DECLARATOR_LIST T_COMMA INIT_DECLARATOR { $$ = new declaratorList($1, $3); }

INIT_DECLARATOR : DECLARATOR { $$ = $1; }
                | DECLARATOR T_EQUALS INITIALIZER { $$ = new initDeclarator($1, $3); }

//STORAGE_CLASS_SPECIFIER : T_TYPEDEF
//                        | T_EXTERN
//                        | T_STATIC
//                        | T_AUTO
//                        | T_REGISTER

TYPE_SPECIFIER : T_INT { $$ = new int_type(); }
//               | T_CHAR
//               | T_SHORT
//               | T_VOID
//               | T_LONG
//               | T_FLOAT
//               | T_DOUBLE
//               | T_SIGNED
//               | T_UNSIGNED
//               | STRUCT_OR_UNION_SPECIFIER // Structs and Unions can be used like types
//               | ENUM_SPECIFIER // Enums can be used like types

//STRUCT_OR_UNION_SPECIFIER : STRUCT_OR_UNION T_IDENTIFIER // Struct or union with name
//                          | STRUCT_OR_UNION T_LCURLY STRUCT_DECLARATION_LIST T_RCURLY // Struct or union with declaration list
//                          | STRUCT_OR_UNION T_IDENTIFIER T_LCURLY STRUCT_DECLARATION_LIST T_RCURLY // Struct or union with name and declaration list

//STRUCT_OR_UNION : T_STRUCT
//                | T_UNION

//STRUCT_DECLARATION_LIST : STRUCT_DECLARATION // Single declaration
//                        | STRUCT_DECLARATION_LIST STRUCT_DECLARATION // Multiple declaration

//STRUCT_DECLARATION : SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST T_SEMICOLON

SPECIFIER_QUALIFIER_LIST : TYPE_SPECIFIER { $$ = $1; }
//                         | TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST // Type specifier and more
//                         | TYPE_QUALIFIER // Just a type qualifier
//                         | TYPE_QUALIFIER SPECIFIER_QUALIFIER_LIST // Type qualifier and more

//STRUCT_DECLARATOR_LIST : STRUCT_DECLARATOR // Single declarator
//                       | STRUCT_DECLARATOR_LIST T_COMMA STRUCT_DECLARATOR // More than one declarator

//STRUCT_DECLARATOR : DECLARATOR
//                  | T_COLON CONSTANT_EXPRESSION
//                  | DECLARATOR T_COLON CONSTANT_EXPRESSION

//ENUM_SPECIFIER : T_ENUM T_LCURLY ENUMERATOR_LIST T_RCURLY // Enum with just list
//               | T_ENUM T_IDENTIFIER T_LCURLY ENUMERATOR_LIST T_RCURLY // Enum with name and list
//               | T_ENUM T_IDENTIFIER // Enum with just name

//ENUMERATOR_LIST : ENUMERATOR // Single enumerator
//                | ENUMERATOR_LIST T_COMMA ENUMERATOR // More than one enumerator

//ENUMERATOR : T_IDENTIFIER // Just the name of the enumerator
//           | T_IDENTIFIER T_EQUALS CONSTANT_EXPRESSION // Name of the enumerator assigned to a constant

//TYPE_QUALIFIER : T_CONST
//               | T_VOLATILE

DECLARATOR : DIRECT_DECLARATOR { $$ = $1; }
//           | POINTER DIRECT_DECLARATOR

DIRECT_DECLARATOR : T_IDENTIFIER { $$ = new varDeclarator($1); }
//                  | T_LBRACKET DECLARATOR T_RBRACKET
//                  | DIRECT_DECLARATOR T_LSQUARE T_RSQUARE
//                  | DIRECT_DECLARATOR T_LSQUARE CONSTANT_EXPRESSION T_RSQUARE
                  | DIRECT_DECLARATOR T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET { $$ = new functionDeclaratorParams($1, $3); }
                  | DIRECT_DECLARATOR T_LBRACKET T_RBRACKET { $$ = new functionDeclarator($1); }
                  | DIRECT_DECLARATOR T_LBRACKET IDENTIFIER_LIST T_RBRACKET { $$ = new functionDeclaratorParams($1, $3); }

//POINTER : T_ASTERISK // Pointer
//        | T_ASTERISK TYPE_QUALIFIER_LIST // Pointer typequal
//        | T_ASTERISK POINTER // Pointer to pointer
//        | T_ASTERISK TYPE_QUALIFIER_LIST POINTER // Pointer typequal to pointer

//TYPE_QUALIFIER_LIST : TYPE_QUALIFIER // Single type qualifer
//                    | TYPE_QUALIFIER_LIST TYPE_QUALIFIER // More than one type qualifer

PARAMETER_TYPE_LIST : PARAMETER_LIST { $$ = $1; };
                    | PARAMETER_LIST T_COMMA T_ELLIPSIS

PARAMETER_LIST : PARAMETER_DECLARATION { $$ = $1; }
               | PARAMETER_LIST T_COMMA PARAMETER_DECLARATION { $$ = new paramList($1, $3); }

PARAMETER_DECLARATION : DECLARATION_SPECIFIERS DECLARATOR { $$ = new paramDeclaration($1, $2); }
//                      | DECLARATION_SPECIFIERS // Just specifiers
//                      | DECLARATION_SPECIFIERS ABSTRACT_DECLARATOR // Specifiers before abstract declarator

IDENTIFIER_LIST : T_IDENTIFIER { $$ = new paramDeclaration(new varDeclarator($1)); }
                | IDENTIFIER_LIST T_COMMA T_IDENTIFIER { $$ = new paramList($1, new paramDeclaration(new varDeclarator($3))); }

TYPE_NAME : SPECIFIER_QUALIFIER_LIST { $$ = $1; }
//          | SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR // Type name with specifiers, qualifiers and abstract type

//ABSTRACT_DECLARATOR : POINTER // Pointer to something
//                    | DIRECT_ABSTRACT_DECLARATOR
//                    | POINTER DIRECT_ABSTRACT_DECLARATOR

// Directly abstract declarators are arrays and functions
//DIRECT_ABSTRACT_DECLARATOR : T_LBRACKET ABSTRACT_DECLARATOR T_RBRACKET // An abstract declarator in brackets
//                           | T_LSQUARE T_RSQUARE // array no size
//                           | T_LSQUARE CONSTANT_EXPRESSION T_RSQUARE // array of size
//                           | DIRECT_ABSTRACT_DECLARATOR T_LSQUARE T_RSQUARE // Array of another abstract declarator no size
//                           | DIRECT_ABSTRACT_DECLARATOR T_LSQUARE CONSTANT_EXPRESSION T_RSQUARE // Array of another abstract declarator of size
//                           | T_LBRACKET T_RBRACKET // Empty brackets
//                           | T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET // Function parameters
//                           | DIRECT_ABSTRACT_DECLARATOR T_LBRACKET T_RBRACKET // Function with no params
//                           | DIRECT_ABSTRACT_DECLARATOR T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET // Function with parameters

INITIALIZER : ASSIGNMENT_EXPRESSION { $$ = new initializerExpr($1); }
//            | T_LCURLY INITIALIZER_LIST T_RCURLY // Regular initialzer list
//            | T_LCURLY INITIALIZER_LIST T_COMMA T_RCURLY // Intiailizer list ending with comma

// INITIALIZER_LIST : INITIALIZER // Single initializer
//                 | INITIALIZER_LIST T_COMMA INITIALIZER // More than one comma seperated initializers

STATEMENT : COMPOUND_STATEMENT { $$ = $1; }
          | EXPRESSION_STATEMENT { $$ = $1; }
//          | LABELED_STATEMENT
          | SELECTION_STATEMENT { $$ = $1; }
          | ITERATION_STATEMENT { $$ = $1; }
          | JUMP_STATEMENT { $$ = $1; }

//LABELED_STATEMENT : T_IDENTIFIER T_COLON STATEMENT
//                  | T_CASE CONSTANT_EXPRESSION T_COLON STATEMENT
//                  | T_DEFAULT T_COLON STATEMENT

COMPOUND_STATEMENT : T_LCURLY T_RCURLY { $$ = new emptyStat(); }
                   | T_LCURLY DECLARATION_LIST T_RCURLY { $$ = new compoundStatDecs($2); }
                   | T_LCURLY STATEMENT_LIST T_RCURLY { $$ = new compoundStat($2); }
                   | T_LCURLY DECLARATION_LIST STATEMENT_LIST T_RCURLY { $$ = new compoundStatDecsStats($2, $3); }

DECLARATION_LIST : DECLARATION { $$ = $1; }
                 | DECLARATION_LIST DECLARATION { $$ = new declarationList($1, $2); }

STATEMENT_LIST : STATEMENT { $$ = $1; }
               | STATEMENT_LIST STATEMENT { $$ = new statList($1, $2); }

EXPRESSION_STATEMENT : T_SEMICOLON { $$ = new emptyStat(); }
                     | EXPRESSION T_SEMICOLON { $$ = new expressionStat($1); }

SELECTION_STATEMENT : T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT %prec "then" { $$ = new selectionStat($3, $5); }
                    | T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT T_ELSE STATEMENT { $$ = new selectionStatElse($3, $5, $7); }
//                    | T_SWITCH T_LBRACKET EXPRESSION T_RBRACKET STATEMENT // Switch

ITERATION_STATEMENT : T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STATEMENT { $$ = new whileStat($3, $5); }
//                    | T_DO STATEMENT T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_SEMICOLON 
//                    | T_FOR T_LBRACKET T_SEMICOLON T_SEMICOLON T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON T_SEMICOLON T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET T_SEMICOLON EXPRESSION T_SEMICOLON T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET T_SEMICOLON T_SEMICOLON EXPRESSION T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON EXPRESSION T_SEMICOLON T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET T_SEMICOLON EXPRESSION T_SEMICOLON EXPRESSION T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON T_SEMICOLON EXPRESSION T_RBRACKET STATEMENT 
//                    | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON EXPRESSION T_SEMICOLON EXPRESSION T_RBRACKET STATEMENT {

JUMP_STATEMENT : T_RETURN T_SEMICOLON { $$ = new returnStat(new voidExpr()); }
               | T_RETURN EXPRESSION T_SEMICOLON { $$ = new returnStat($2); }
//               | T_GOTO T_IDENTIFIER T_SEMICOLON
//               | T_CONTINUE T_SEMICOLON 
//               | T_BREAK T_SEMICOLON 

TRANSLATION_UNIT : EXTERNAL_DECLARATION { $$ = $1; }
                 | EXTERNAL_DECLARATION TRANSLATION_UNIT { $$ = new translationUnit($1, $2); }

EXTERNAL_DECLARATION : DECLARATION { $$ = $1; }
                     | FUNCTION_DEFINITION { $$ = $1; }

FUNCTION_DEFINITION : DECLARATION_SPECIFIERS DECLARATOR COMPOUND_STATEMENT { $$ = new functionDef($1, $2, $3); }
                    | DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT { $$ = new functionDefDeclList(new int_type(), $1, $2, $3); }
                    | DECLARATOR COMPOUND_STATEMENT { $$ = new functionDef(new int_type(), $1, $2); }
                    | DECLARATION_SPECIFIERS DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT { $$ = new functionDefDeclList($1, $2, $3, $4); }

CONSTANT : T_INT_CONSTANT { $$ = new int_constant($1); }
         //| T_FLOAT_CONSTANT
         //| T_CHAR_CONSTANT


%%
const Node* root; // Store the root of the AST
const Node* parse()
{
        root = NULL;
        yyparse();
        return root;
}