/*
 * Fiahil
 *
 * 3 Mai 2012
 */

%{
#include <string>
#include "Scanner.hpp"

#define YY_USER_ACTION yylloc->columns(yyleng);

%}

%option nodefault yyclass="Scanner" noyywrap c++

%%

%{
   yylloc->step();
%}

"FOOBAR"	{ return Serializer::Parser::token::FOOBAR; }
"\n"		{ return Serializer::Parser::token::EOL; }
