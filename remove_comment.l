%{
#include<stdio.h>

%}
 

%%
\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {};
%%
 
int main()
{
    yyin=fopen("hornyCode.c","r");
    yyout=fopen("hornyCode_out.c","w");
    yylex();
    
     
}

int yywrap()
{
    return 1;
}
