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

%option yyclass="Scanner" noyywrap c++

%%

%{
   yylloc->step();
%}

"#INFO"		{ yylval->sval = new std::string(yytext, yyleng); return Serializer::Parser::token::INFO; }
"#STAT"		{ return Serializer::Parser::token::STAT; }
"#SKILLS"	{ return Serializer::Parser::token::SKILLS; }
"#ACHIEVEMENTS"	{ return Serializer::Parser::token::ACHIEVEMENTS; }
"#SAVES"	{ return Serializer::Parser::token::SAVES; }
"#CONFIG"	{ return Serializer::Parser::token::CONFIG; }
"#ENDCONFIG"	{ return Serializer::Parser::token::ENDCONFIG; }
"\n"		{ return Serializer::Parser::token::EOL; }
":"		{ return Serializer::Parser::token::SEP; }
[0-9]+		{ return Serializer::Parser::token::NUMBER; }
[A-Za-z_-]+	{ return Serializer::Parser::token::WORD; }

[ \t\r]+	{ yylloc->step(); }
