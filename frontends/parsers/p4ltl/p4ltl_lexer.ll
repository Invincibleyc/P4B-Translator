%{
	enum tokentype {
		GLOBAL,
		FUTURE,
		HEADER
	}	
%}

%x TEMPORAL

%%

[a-zA-Z]+ {words++; chars += strlen(yytext); printf("yytext:%s\n", yytext);}
\n		  {chars++; lines++;}
.		  {chars++;}

%%

main(int argc, char** argv)
{
	yylex();
	printf("%d%d%d\n", lines, words, chars);
}