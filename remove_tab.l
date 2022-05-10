%{
#include<stdio.h>
%}

%%

[\t]+ { printf("\t"); fprintf(yyout,"\t"); }
[\n]+ { printf("\n"); fprintf(yyout,"\n"); }
. { printf("%s",yytext); fprintf(yyout,"%s",yytext); }


%%
int yywrap(){}

int main(){
	yyin=fopen("input.txt","r");
	yyout=fopen("output.txt","w");
	yylex();
    return 0;
}
