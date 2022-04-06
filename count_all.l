%{
#include<stdio.h>
int line=0, digits=0,charac=0, word=0, total=0,spch=0;
%}
 

%%
\n {line++; word++;} //line counter
[\t ' '] word++;
[0-9] digits++; //digit counter
[a-zA-Z] charac++; //character counter 
. spch++;     //special characters counter
%%
 
int main()
{
    yyin=fopen("ref.txt","r");
    yylex();
    total=charac+digits+spch;
    printf("\n File contains ..\n");
    printf("\n No. of lines=%d", line); 
    printf("\n No. of digits=%d", digits); 
    printf("\n No. of words=%d", word);
    printf("\n No. of characters=%d", charac);  
    printf("\n No. of special characters=%d", spch);  
    printf("\n Total = %d\n", total);
     
}

int yywrap()
{
    return 1;
}
