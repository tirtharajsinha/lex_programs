%{
#include<stdio.h>

%}
 

%%
\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {};
%%
 
int main()
{
    yyin=fopen("hello.c","r");
    yyout=fopen("hello_out.c","w");
    yylex();
    
     
}

int yywrap()
{
    return 1;
}
