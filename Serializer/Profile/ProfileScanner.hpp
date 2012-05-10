/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>

#ifndef __PROFILESCANNER_HPP__
#define __PROFILESCANNER_HPP__

#undef yyFlexLexer
#define yyFlexLexer yyprofile_FlexLexer

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int	Serializer::Profile::Scanner::yylex()

#include "ProfileLoader.tab.hpp"

namespace Serializer {
  namespace Profile {
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
