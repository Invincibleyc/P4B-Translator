#ifndef P4LTLLEXER_H
#define P4LTLLEXER_H

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

namespace P4LTL { // note: depends upon FlexLexer.h and p4LTLParser.hpp

class P4LTLParser;

class Scanner : public yyFlexLexer {
public:
    Scanner(std::istream& arg_yyin, std::ostream& arg_yyout)
        : yyFlexLexer(arg_yyin, arg_yyout) {}
    Scanner(std::istream* arg_yyin = nullptr, std::ostream* arg_yyout = nullptr)
        : yyFlexLexer(arg_yyin, arg_yyout) {}
    int lex(P4LTLParser::semantic_type *yylval); // note: this is the prototype we need
};
 
} // namespace P4LTL

#endif