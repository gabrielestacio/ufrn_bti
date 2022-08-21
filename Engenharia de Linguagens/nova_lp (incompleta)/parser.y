%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%token ID
%token INT REAL BOOLEAN CHAR STRING VOID TYPE CONSTANT
%token FUNCTION MAIN
%token FOR TO WHILE IF ELSE ELSE_IF SWITCH CASE DEFAULT BREAK RETURN
%token BLOCK_BEGIN BLOCK_END LEFT_PARENTHESIS RIGHT_PARENTHESIS RIGHT_BRACKET LEFT_BRACKET CASE_BEGIN COMMA SEMI
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN DIV_ASSIGN TIMES_ASSIGN
%token DOUBLE_PLUS DOUBLE_MINUS
%token PLUS MINUS DIV TIMES POWER MODULE
%token AND OR NOT EQUAL NOT_EQUAL GREATER SMALLER EQ_GREATER EQ_SMALLER

%start program

%type stmt

%%

/*ESTRUTURA GERAL DE UM PROGRAMA*/
program : decl_section sub_programs main 					{}
    ;

decl_section :  | decl_list				{}
	;

/*MÚLTIPLAS DECLARAÇÕES*/
decl_list : decl | decl_list decl 						{}
	;

/*SENTENÇA DE DECLARAÇÃO*/
decl : TYPE id_list SEMI							{}
	   | const_decl SEMI							{}
	;

/*FORMA DE DECLARAÇÃO DE UMA CONSTANTE*/
const_decl : CONSTANT TYPE ID ASSIGN expression SEMI	{}
	;

/*LISTA DE IDS*/
id_list : ID dimensions								{}
		  | ID dimensions ASSIGN expression					{}
		  | id_list COMMA ID dimensions ASSIGN expression		{}
		  | id_list COMMA ID dimensions						{}
	;

/*DIMENSÕES DE UM ID*/
dimensions :  | dimensions LEFT_BRACKET expression RIGHT_BRACKET		{}
	;

/*EXPRESSÃO COM PRECEDÊNCIA MÍNIMA*/
expression : expression exp_operator term 		{}
			 | term 							{}
	;

/*OPERADORES DE PRECEDÊNCIA MÍNIMA (ADIÇÃO E SUBTRAÇÃO)*/
exp_operator : PLUS | MINUS 			{}
	;

/*EXPRESSÃO COM PRECEDÊNCIA DE 3º NÍVEL*/
term : term term_operator factor		{}
	   | factor							{}
	;

/*OPERADORES DE PRECEDÊNCIA DE 3º NÍVEL (MULTIPLICAÇÃO E DIVISÃO)*/
term_operator : TIMES | DIV | MODULE	{}
	;

/*EXPRESSÃO DE PRECEDÊNCIA DE 2º NÍVEL (EXPONENCIAÇÃO)*/
factor : base POWER factor		{}
		 | base					{}
	;

/*EXPRESSÃO DE PRECEDÊNCIA MÁXIMA (PARÊNTESES, IDENTIFICADOR, LITERAL OU CHAMADA DE FUNÇÃO)*/
/*TROCAR ESSE NOME*/
base : LEFT_PARENTHESIS expression RIGHT_PARENTHESIS
	   | ID dimensions 					{}
	   | ID dimensions double_sign		{}
	   | literal 				{}
	   | func_call				{}
	;

/*SIGNIFICADO DE LITERAL*/
literal : INT | REAL | BOOLEAN | CHAR | STRING		{}
	;

/*CHAMADA DE FUNÇÃO*/
func_call : ID LEFT_PARENTHESIS args RIGHT_PARENTHESIS			{}
	;

/*POSSIBILIDADES DE LISTA DE ARGUMENTOS DE UMA CHAMADA DE FUNÇÃO*/
args:  | arg_list			{}
	;

/*ARGUMENTOS DE UMA CHAMADA DE FUNÇÃO*/
/*OBSERVAR*/
arg_list : arg | arg_list COMMA arg			{}
	;

/*TIPOS DE ARGUMENTO PARA UMA CHAMADA DE FUNÇÃO*/
arg : ID dimensions | literal | func_call			{}
	;

/*LISTA DE SUB-PROGRAMAS*/
sub_programs :  | sub_programs sub_program				{}
	;

/*DESCRIÇÃO DE UM SUB-PROGRAMA*/
sub_program : FUNCTION TYPE ID LEFT_PARENTHESIS params RIGHT_PARENTHESIS BLOCK_BEGIN body return_stmt  BLOCK_END		{}
			  | FUNCTION VOID ID LEFT_PARENTHESIS params RIGHT_PARENTHESIS BLOCK_BEGIN body BLOCK_END					{}
	;

params :  | param_list 			{}
	;

param_list : param | param_list COMMA param 			{}
	;

param : TYPE ID dimensions					{}
	;

body : | decl_list | decl_list stmt_list SEMI | stmt_list SEMI			{}
	;

/*LISTA DE INSTRUÇÕES DE UM BLOCO*/
stmt_list : stmt | stmt_list stmt  {}
    ;

/*FORMAS DE UMA INSTRUÇÃO/LINHA DE CÓDIGO*/
stmt :   assign_stmt             {}
	   | if_else_stmt		{}
	   | switch_case_stmt	{}
	   | while_stmt			{}
	   | for_stmt			{}
    ;

assign_stmt : ID dimensions assign_opt SEMI {}
         ;

assign_opt : assignment_sign expression  {}
	         | double_sign               {}
	         ;

/*SINAIS DE ATRIBUIÇÃO POSSÍVEIS*/
assignment_sign : ASSIGN 					{}
				  | PLUS_ASSIGN				{}
				  | MINUS_ASSIGN			{}
				  | DIV_ASSIGN				{}
				  | TIMES_ASSIGN			{}
	;

/*SINAIS DE INCREMENTO E DECREMENTO*/
double_sign : DOUBLE_PLUS | DOUBLE_MINUS			{}
	;

/*CONDICIONAL IF/ELSE*/
if_else_stmt : if_stmt else_section 		{}
	;

/*FORMA DA INSTRUIÇÃO IF*/
if_stmt : IF compare BLOCK_BEGIN stmt_section breaker BLOCK_END			{}
	;

/*COMPARAÇÃO QUE É A CONDIÇÃO DO IF*/
compare : comparation				{}
		  | compare logic_operator comparation			{}
	;

comparation : comparison			{}
			  | NOT comparison

comparison : LEFT_PARENTHESIS ID dimensions compare_operator expression RIGHT_PARENTHESIS								{}
	;

/*OPERADORES DE COMPARAÇÃO*/
compare_operator : EQUAL | NOT_EQUAL | GREATER | SMALLER | EQ_GREATER | EQ_SMALLER			{}
	;

/*OPERADORES LÓGICOS*/
logic_operator : AND | OR			{}
	;

/*ALTERADORES DE FLUXO*/
/*TROCAR ESSE NOME*/
breaker :  | BREAK SEMI | return_stmt			{}
	;

/*INSTRUÇÃO DE RETORNO*/
return_stmt : RETURN expression SEMI			{}
	;

/*PARTE "ELSE" DO CONDICIONAL*/
/*TROCAR O NOME*/
else_section :  | else_if_stmt else_section | else_stmt 			{}
	;

/*FORMA DE UMA INSTRUÇÃO ELSE IF*/
else_if_stmt : ELSE_IF compare BLOCK_BEGIN stmt_section breaker BLOCK_END			{}
	;

/*FORMA DE UMA INSTRUÇÃO ELSE*/
else_stmt : ELSE BLOCK_BEGIN stmt_section breaker BLOCK_END			{}
	;

/*CONDICIONAL SWITCH/CASE*/
switch_case_stmt : switch_stmt BLOCK_BEGIN case_section default_stmt BLOCK_END			{}
	;

/*FORMA DE INICIAR O CONDICIONAL SWITCH/CASE*/
switch_stmt : SWITCH LEFT_PARENTHESIS ID dimensions RIGHT_PARENTHESIS			{}
	;

case_section : case_stmt | case_section case_stmt 					{}
	;

/*FORMA DA INSTRUÇÃO CASE*/
case_stmt : CASE literal CASE_BEGIN stmt_section BREAK SEMI 			{}
	;

/*FORMA DO CASO DEFAULT*/
default_stmt : DEFAULT CASE_BEGIN stmt_section BREAK SEMI			{}
	;

/*FORMA DE UM LAÇO DE REPETIÇÃO WHILE*/
while_stmt : WHILE compare BLOCK_BEGIN stmt_section breaker BLOCK_END			{}
	;

/*FORMA DE UM LAÇO DE REPETIÇÃO FOR*/
for_stmt : FOR LEFT_PARENTHESIS ID dimensions ASSIGN expression RIGHT_PARENTHESIS TO expression BLOCK_BEGIN stmt_section breaker BLOCK_END			{}
	;

/*FORMA DO BLOCO PRINCIPAL DO PROGRAMA*/
main : FUNCTION MAIN LEFT_PARENTHESIS RIGHT_PARENTHESIS BLOCK_BEGIN stmt_section BLOCK_END			{}
	;

stmt_section :  | decl_list | decl_list stmt_list | stmt_list                 {}
    ;

%%

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
