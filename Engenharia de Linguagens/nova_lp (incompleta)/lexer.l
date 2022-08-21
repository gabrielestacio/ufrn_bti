%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
%}

%%

[ \t\n]               ;
[0-9]+           	    {return INT;}
[0-9]+"."[0-9]+         {return REAL;}
([Tt][Rr][Uu][Ee]|[Ff][Aa][Ll][Ss][Ee])     {return BOOLEAN;}
\[a-zA-Z]                {return CHAR;}
\"(\\.|[^"\\])*\"       {return STRING;}
"void"					{return VOID;}
("int"|"char"|"string"|"real"|"boolean")			{return(TYPE);}
"const"             {return(CONSTANT);}
"function"          {return(FUNCTION);}
"main"              {return(MAIN);}
"for"      			    {return(FOR);}
"to"                {return(TO);}
"while"      			    {return(WHILE);}
"if"                  {return(IF);}
"else"                {return(ELSE);}
"else if"             {return(ELSE_IF);}
"switch"                    {return(SWITCH);}
"case"                      {return(CASE);}
"default"                   {return(DEFAULT);}
"break"                     {return(BREAK);}
"return"                    {return(RETURN);}
"{"               {return(BLOCK_BEGIN);}
"}"                 {return(BLOCK_END);}
"("                         {return(LEFT_PARENTHESIS);}
")"                         {return(RIGHT_PARENTHESIS);}
"["							{return(LEFT_BRACKET);}
"]"							{return(RIGHT_BRACKET);}
":"                         {return(CASE_BEGIN);}
","							{return(COMMA);}
";"      				      {return(SEMI);}
":="					        {return(ASSIGN);}
"+="						{return(PLUS_ASSIGN);}
"-="						{return(MINUS_ASSIGN);}
"/="						{return(DIV_ASSIGN);}
"*="						{return(TIMES_ASSIGN);}
"++"						{return(DOUBLE_PLUS);}
"--"						{return(DOUBLE_MINUS);}
"+"                         {return(PLUS);}
"-"                         {return(MINUS);}
"/"                         {return(DIV);}
"*"                         {return(TIMES);}
"**"                        {return(POWER);}
"%"                         {return(MODULE);}
"&&"						{return(AND);}
"||"						{return(OR);}
"!"							{return(NOT);}                        
"=="                        {return(EQUAL);}
"!="                        {return(NOT_EQUAL);}
">"                         {return(GREATER);}
"<"                         {return(SMALLER);}
">="                        {return(EQ_GREATER);}
"<="                        {return(EQ_SMALLER);}
(\/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/)|(\/\/.*) {printf("Comment: %s.\n", yytext);}
[a-zA-Z][a-zA-Z0-9]*  {return ID;}
.                      {printf("invalid character");}

%%

#ifndef yywrap

int yywrap (void){
    return 1;
}

#endif
