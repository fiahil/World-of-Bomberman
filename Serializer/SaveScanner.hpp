/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>

#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int	Serializer::Scanner::yylex()

#include "Parser.tab.h"

namespace Serializer {
  class Scanner : public yyFlexLexer {
  public:
    Scanner(std::istream& in) : yyFlexLexer(&in, 0) { }

    inline int	yylex(Parser::semantic_type* lval, Parser::location_type* lloc);

  private:
    Parser::semantic_type*	yylval;
    Parser::location_type*	yylloc;

  private:
    Scanner();
    Scanner(Scanner const&);
    Scanner&	operator=(Scanner const&);

    int		yylex();
  };

  int Scanner::yylex(Parser::semantic_type* lval, Parser::location_type* lloc) {
    yylval = lval;
    yylloc = lloc;
    return yylex();
  }
}

#endif /* __SCANNER_HPP__ */
