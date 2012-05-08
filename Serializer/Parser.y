/*
 * Fiahil
 *
 * 8 Mai 2012
 */

%require "2.5"
%skeleton "lalr1.cc"
%defines
%locations
%define namespace Serializer
%define parser_class_name "Parser"
%parse-param { Serializer::Scanner &scanner }
%parse-param { std::string currentSection }
%lex-param   { Serializer::Scanner &scanner }

%code requires {
#include <string>
#include <sstream>

#define YYSTYPE	std::string

  namespace Serializer {
    class Scanner;
  }
 }

%code {
  static int yylex(Serializer::Parser::semantic_type* yylval,
		   Serializer::Parser::location_type* yylloc,
		   Serializer::Scanner &scanner);
 }

%token FOOBAR EOL

%%

input :
| input line
| line
;

line :
| value
| eol
;

value	: FOOBAR { std::cout << "Foobar" << std::endl; }
eol	: EOL { std::cout << "New Line!" << std::endl; }

%%

namespace Serializer {
  void		Parser::error(Parser::location_type const& loc,
			      std::string const& msg) {
    std::ostringstream	ret;

    ret << "Parser Error at " << loc << ": " << msg;
    throw ret.str();
  }
}

#include "Scanner.hpp"
static int	yylex(Serializer::Parser::semantic_type* yylval,
		      Serializer::Parser::location_type* yylloc,
		      Serializer::Scanner &scanner) {
  return scanner.yylex(yylval, yylloc);
}
