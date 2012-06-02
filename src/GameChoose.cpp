/*
 * NicoW
 * 27.05.12
 */

#include <iostream>
#include "GameChoose.hpp"

GameChoose::GameChoose(GameManager& game)
  : AMenu("menu/background/backgroundGameMode.jpg", "menu/background/backgroundGameMode.jpg", 0.0f, -1.0f, 1600.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/SoloNormal.png", "menu/tags/SoloHighlit.png", true, false, TokenMenu::IA, 429.0f, 0.0f, 1950.0f));
  this->_tags.push_back(new Tag("menu/tags/CoopNormal.png", "menu/tags/CoopHighlit.png", false, false, TokenMenu::IA, 429.0f, 0.0f, 2015.0f));
  this->_tags.push_back(new Tag("menu/tags/VersusNormal.png", "menu/tags/VersusHighlit.png", false, false, TokenMenu::IA, 429.0f, 0.0f, 2080.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::PROFILE, 429.0f, 0.0f, 2145.0f));
}

GameChoose::~GameChoose(void)
{
}

double		GameChoose::getCenterX(void) const
{
  return (800.0f);
}

double		GameChoose::getCenterY(void) const
{
  return (2000.0f);
}

void		GameChoose::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::IA)
    {
      if (!this->_cursor)
	this->_gameManager._match._gameMode = GameMode::SOLO;
      else
	if (this->_cursor == 1)
	  this->_gameManager._match._gameMode = GameMode::COOP;
	else if (this->_cursor == 2)
	  this->_gameManager._match._gameMode = GameMode::VERSUS;
    }
}
