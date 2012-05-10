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
  return Serializer::Profile::Loader::token::INFO;
}

"#STAT"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::STAT;
}

"#SKILLS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::SKILLS;
}

"#ACHIEVEMENTS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::ACHIEVEMENTS;
}

"#SAVES"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::SAVES;
}

"#CONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::CONFIG;
}

"#ENDCONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::ENDCONFIG;
}

"\n"		{
  yylval->sval = new std::string(yytext, yyleng);
  yylloc->lines(1);
  return Serializer::Profile::Loader::token::EOL;
}

":"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::SEP;
}

[0-9]+		{
  std::istringstream	ss(yytext);

  ss >> yylval->ival;
  return Serializer::Profile::Loader::token::NUMBER;
}

[A-Za-z_-]+	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Profile::Loader::token::WORD;
}

[ \t\r]+	{
  yylloc->step();
}
