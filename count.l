%{
int vowel=0;
int cons=0;
%}

%%

[aeiouAEIOU] {vowel++;}
[a-zA-Z] {cons++;}

%%

int yywrap(){}

int main(){
	printf("Enter a char : ");
        yylex();
	printf("NUMBER OF VOWELS= %d and CONSONENT=%d",vowel,cons);
	return 0;
	
}