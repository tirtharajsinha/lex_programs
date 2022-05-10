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
  yyin = fopen("hornyCode.c", "r");
  yyout = fopen("output.c", "w");
  yylex();
  printf("Number of scanfs = %d \n Number of printfs = %d\n",print,scan);
  return 0;
}
