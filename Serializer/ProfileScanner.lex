/*
 * Fiahil
 *
 * 3 Mai 2012
 */

%{
#include <string>
#include <sstream>
#include "Scanner.hpp"

#define YY_USER_ACTION yylloc->columns(yyleng);

%}

%option yyclass="Scanner" noyywrap c++

%%

%{
   yylloc->step();
%}

"#INFO"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::INFO;
}

"#STAT"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::STAT;
}

"#SKILLS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::SKILLS;
}

"#ACHIEVEMENTS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::ACHIEVEMENTS;
}

"#SAVES"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::SAVES;
}

"#CONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::CONFIG;
}

"#ENDCONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::ENDCONFIG;
}

"\n"		{
  yylval->sval = new std::string(yytext, yyleng);
  yylloc->lines(1);
  return Serializer::Parser::token::EOL;
}

":"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::SEP;
}

[0-9]+		{
  std::istringstream	ss(yytext);

  ss >> yylval->ival;
  return Serializer::Parser::token::NUMBER;
}

[A-Za-z_-]+	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Parser::token::WORD;
}

[ \t\r]+	{
  yylloc->step();
}
