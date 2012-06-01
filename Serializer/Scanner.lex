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
  return Serializer::Loader::token::INFO;
}

"#STAT"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::STAT;
}

"#ACHIEVEMENTS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::ACHIEVEMENTS;
}

"#SAVES"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::SAVES;
}

"#CONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::CONFIG;
}

"#ENDCONFIG"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::ENDCONFIG;
}

"#MAP"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::MAP;
}

"#ENDMAP"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::ENDMAP;
}

"#HEADER"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::HEADER;
}

"#PLAYERS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::PLAYERS;
}

"#ENDPLAYERS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::ENDPLAYERS;
}

"#DEADS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::DEADS;
}

"#ENDDEADS"	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::ENDDEADS;
}

"\n"		{
  yylval->sval = new std::string(yytext, yyleng);
  yylloc->lines(1);
  return Serializer::Loader::token::EOL;
}

":"		{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::SEP;
}

[0-9]+		{
  std::istringstream	ss(yytext);

  ss >> yylval->ival;
  return Serializer::Loader::token::NUMBER;
}

[A-Za-z_-]+	{
  yylval->sval = new std::string(yytext, yyleng);
  return Serializer::Loader::token::WORD;
}

\[[A-Za-z0-9_-]+\]	{
  yylval->sval = new std::string(yytext + 1, yyleng - 2);
  return Serializer::Loader::token::MIXTE;
}

[ \t\r]+	{
  yylloc->step();
}
