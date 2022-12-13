%option c++ interactive noyywrap noyylineno nodefault
%option outfile="lex.yy.c"

%x PREDICATE

%{
  #include <cstdio>
  #include <cstdlib>
  #include "frontends/parsers/p4ltl/p4ltlparser.hpp"
  #include "frontends/parsers/p4ltl/p4ltllexer.hpp"
  #undef  YY_DECL
  #define YY_DECL int P4LTL::Scanner::lex(P4LTL::P4LTLParser::semantic_type *yylval)

  int parens = 0;

  void echoToken(const char* yytext);
  typedef P4LTL::P4LTLParser::token token;
%}

LineTerminator \r|\n|\r\n
ws {LineTerminator}|[ \t\f]

Identifier [_a-zA-Z~][a-zA-Z0-9_~#\.]*
Header [_a-zA-Z~][a-zA-Z0-9_~#\.]*
DecIntegerLiteral 0|[1-9][0-9]*
HexIntegerLiteral [0][xX][0-9a-fA-F]+

%%
<INITIAL>"("					{echoToken(yytext); return token::LPAR; }
<INITIAL>")"					{echoToken(yytext); return token::RPAR; }

<INITIAL>"AP"				{echoToken(yytext); BEGIN(PREDICATE); return token::AP; }

<INITIAL>"[]"				{echoToken(yytext); return token::ALWAYS; }
<INITIAL>"<>"				{echoToken(yytext); return token::EVENTUALLY; }
<INITIAL>"U"					{echoToken(yytext); return token::UNTIL; }
<INITIAL>"W"					{echoToken(yytext); return token::WEAKUNTIL; }
<INITIAL>"R"					{echoToken(yytext); return token::RELEASE; }
<INITIAL>"&&"				{echoToken(yytext); return token::AND; }
<INITIAL>"||"				{echoToken(yytext); return token::OR; }
<INITIAL>"==>"				{echoToken(yytext); return token::IMPLIES; }
<INITIAL>"X"					{echoToken(yytext); return token::NEXT; }
<INITIAL>"!"					{echoToken(yytext); return token::NEG; }

<INITIAL>{ws}    			{/* ignore */ }
<INITIAL>{Identifier}    	{echoToken(yytext);
                           yylval->emplace<const char*>(strdup(yytext));
                           return token::NAME; }

<PREDICATE>"("						{echoToken(yytext); parens++; return token::LPAR; }
<PREDICATE>"=="					{echoToken(yytext); return token::EQ; }
<PREDICATE>"<="					{echoToken(yytext); return token::LEQ; }
<PREDICATE>">="					{echoToken(yytext); return token::GEQ; }
<PREDICATE>">"						{echoToken(yytext); return token::GT; }
<PREDICATE>"<"						{echoToken(yytext); return token::LT; }
<PREDICATE>"!="					{echoToken(yytext); return token::NEQ; }
<PREDICATE>")"						{echoToken(yytext); parens--; if(parens == 0) { BEGIN(INITIAL); } return token::RPAR; }
<PREDICATE>","						{echoToken(yytext); return token::COMMA; }
<PREDICATE>"old"					{echoToken(yytext); return token::OLD; }
<PREDICATE>"Key"					{echoToken(yytext); return token::KEY; }
<PREDICATE>"+"						{echoToken(yytext); return token::PLUS; }
<PREDICATE>"-"						{echoToken(yytext); return token::MINUS; }
<PREDICATE>"*"						{echoToken(yytext); return token::MULTIPLY; }
<PREDICATE>"!"						{echoToken(yytext); return token::NEG; }
<PREDICATE>"&&"					{echoToken(yytext); return token::AND; }
<PREDICATE>"||"					{echoToken(yytext); return token::OR; }
<PREDICATE>"==>"					{echoToken(yytext); return token::IMPLIES; }
<PREDICATE>"true"					{echoToken(yytext); return token::TRUE; }
<PREDICATE>"false"					{echoToken(yytext); return token::FALSE; }
<PREDICATE>"fwd"					{echoToken(yytext); return token::FWD; }
<PREDICATE>"drop"					{echoToken(yytext); return token::DROP; }
<PREDICATE>"valid"					{echoToken(yytext); return token::VALID; }
<PREDICATE>"Apply"					{echoToken(yytext); return token::APPLY; }
<PREDICATE>"["						{echoToken(yytext); return token::LBRACKET; }
<PREDICATE>"]"						{echoToken(yytext); return token::RBRACKET; }

<PREDICATE>{ws}    				{/* ignore */ }
<PREDICATE>{Header}	    		{echoToken(yytext);
                             yylval->emplace<const char*>(strdup(yytext));
                             return token::NAME; }
<PREDICATE>{HexIntegerLiteral}		{echoToken(yytext);
                                   yylval->emplace<int>(std::strtol(yytext, nullptr, 16));
                                   return token::INT; }
<PREDICATE>{DecIntegerLiteral}		{echoToken(yytext);
                                   yylval->emplace<int>(std::strtol(yytext, nullptr, 10));
                                   return token::INT; }


%%

// note: not <<EOF>> processing

int yyFlexLexer::yylex() {
    throw std::runtime_error("Bad call to yyFlexLexer::yylex()");
}

void echoToken(const char* yytext)
{
  // only for debug
  // printf("Token: %s\n", yytext);
}