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
%parse-param	{ Serializer::Scanner &scanner }
%lex-param	{ Serializer::Scanner &scanner }
%destructor	{ delete $$.sval; } "identifier"

%code requires {
#include <string>
#include <stdexcept>
#include <sstream>

  namespace Serializer {
    class Scanner;
  }
 }

%code {
  static int yylex(Serializer::Parser::semantic_type* yylval,
		   Serializer::Parser::location_type* yylloc,
		   Serializer::Scanner &scanner);
 }

%union
 {
   int		ival;
   std::string*	sval;
};

%token <sval> INFO STAT SKILLS ACHIEVEMENTS SAVES
%token <sval> CONFIG ENDCONFIG
%token <sval> WORD
%token <ival> NUMBER
%token EOL SEP

%%

input
: input line
| line
;

line
: value
| eol
| all
;


value	: INFO { std::cout << *$1 << std::endl; }
eol	: EOL { std::cout << "New Line!" << std::endl; }
all
: NUMBER
| WORD
| CONFIG
| ENDCONFIG
| SEP
| STAT
| SKILLS
| ACHIEVEMENTS
| SAVES
{ std::cout << *$1 << std::endl; }

%%

namespace Serializer {
  void		Parser::error(Parser::location_type const& loc,
			      std::string const& msg) {
    std::ostringstream	ret;

    ret << "- Parse error at line " << loc.begin.line
	<< " column " << loc.begin.column << ":\n-- " << msg;
    throw std::runtime_error(ret.str());
  }
}

#include "Scanner.hpp"
static int	yylex(Serializer::Parser::semantic_type* yylval,
		      Serializer::Parser::location_type* yylloc,
		      Serializer::Scanner &scanner) {
  return scanner.yylex(yylval, yylloc);
}
