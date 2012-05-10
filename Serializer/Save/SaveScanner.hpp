/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>

#ifndef __SAVESCANNER_HPP__
#define __SAVESCANNER_HPP__

#undef yyFlexLexer
#define yyFlexLexer yysave_FlexLexer

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int	Serializer::Save::Scanner::yylex()

#include "SaveLoader.tab.hpp"

namespace Serializer {
  namespace Save {
    class Scanner : public yyFlexLexer {
    public:
      Scanner(std::istream& in) : yyFlexLexer(&in, 0) { }

      inline int yylex(Loader::semantic_type* lval, Loader::location_type* lloc);

    private:
      Loader::semantic_type*	yylval;
      Loader::location_type*	yylloc;

    private:
      Scanner();
      Scanner(Scanner const&);
      Scanner&	operator=(Scanner const&);

      int		yylex();
    };

    int Scanner::yylex(Loader::semantic_type* lval, Loader::location_type* lloc) {
      yylval = lval;
      yylloc = lloc;
      return yylex();
    }
  }
}

#endif /* __SCANNER_HPP__ */
