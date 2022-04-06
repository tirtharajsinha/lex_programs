%{
#include <stdio.h>
int print = 0, scan = 0;
%}

%%
"printf" {print++; fprintf(yyout, "readf");}
"scanf" {scan++; fprintf(yyout, "writef");}

%%

int yywrap(){}
int main()
{
  yyin = fopen("hello.c", "r");
  yyout = fopen("helo_out1.c", "w");
  yylex();
  printf("Number of scanfs = %d \n Number of printfs = %d\n",scan,print);
  return 0;
}
