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
   size_t	ival;
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
: EOL	{}
| info
;

info
: INFO SEP NUMBER SEP WORD SEP NUMBER SEP NUMBER SEP NUMBER SEP NUMBER EOL
{
  std::cout << *$1 << ":"
	    << "\n- id: " << $3
	    << "\n- nick: " << *$5
	    << "\n- lvl: " << $7
	    << "\n- xp: " << $9
	    << "\n- tutorial: " << $11
	    << "\n- skin: " << $13
	    << std::endl << std::endl;
}
| STAT SEP NUMBER SEP NUMBER SEP NUMBER SEP NUMBER SEP NUMBER EOL
{
  std::cout << *$1 << ":"
	    << "\n- Stamina: " << $3
	    << "\n- Strength: " << $5
	    << "\n- Agility: " << $7
	    << "\n- Intellect: " << $9
	    << "\n- Spirit: " << $11
	    << std::endl << std::endl;
}
| SKILLS SEP NUMBER SEP NUMBER SEP NUMBER EOL
{
  std::cout << *$1 << ":"
	    << "\n- DPS: " << $3
	    << "\n- Tank: " << $5
	    << "\n- Heal: " << $7
	    << std::endl << std::endl;
}
| ACHIEVEMENTS SEP NUMBER SEP NUMBER SEP NUMBER EOL
{
  std::cout << *$1 << ":"
	    << "\n- First blood: " << $3
	    << "\n- Last one standing: " << $5
	    << "\n- Immortal: " << $7
	    << std::endl << std::endl;
}
| SAVES sequence
| CONFIG EOL config
;

sequence
: EOL
| SEP NUMBER sequence
{
  std::cout << "- Slot: " << $2 << std::endl;
}

config
: ENDCONFIG
| WORD SEP NUMBER SEP WORD EOL config
{
  std::cout << *$1 << ":\t" << $3 << " ; " << *$5 << std::endl;
}


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
