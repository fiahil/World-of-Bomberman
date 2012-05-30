/*
 * lemonn_v
 * 15.05.12
 */

#include <iostream>
#include "MenuPause.hpp"

MenuPause::MenuPause(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 3200.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/ResumeNormal.png", "menu/ResumeHighlit.png", true, false, TokenMenu::PAUSE, 4000.0f, 0.0f, 450.0f));
  this->_tags.push_back(new Tag("menu/RestartNormal.png", "menu/RestartHighlit.png", false, false, TokenMenu::CREATEGAME, 4000.0f, 0.0f, 500.0f));
  this->_tags.push_back(new Tag("menu/SaveNormal.png", "menu/SaveHighlit.png", false, false, TokenMenu::PAUSE, 4000.0f, 0.0f, 550.0f));
  this->_tags.push_back(new Tag("menu/MainMenuNormal.png", "menu/MainMenuHighlit.png", false, false, TokenMenu::PAUSE, 4000.0f, 0.0f, 600.0f));
  this->_tags.push_back(new Tag("menu/QuitNormal.png", "menu/QuitHighlit.png", false, false, TokenMenu::QUIT, 4000.0f, 0.0f, 650.0f));
}

MenuPause::~MenuPause()
{

}

double	MenuPause::getCenterX() const
{
  return 4000.0f;
}

double	MenuPause::getCenterY() const
{
  return 450.0f;
}

void	MenuPause::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      while (this->_gameManager._match._players.size())
	{
	  delete this->_gameManager._match._players.back();
	  this->_gameManager._match._players.pop_back();
	}
      while (this->_gameManager._match._bombs.size())
	{
	  delete this->_gameManager._match._bombs.back();
	  this->_gameManager._match._bombs.pop_back();
	}
      while (this->_gameManager._match._bonus.size())
	{
	  delete this->_gameManager._match._bonus.back();
	  this->_gameManager._match._bonus.pop_back();
	}
      while (this->_gameManager._match._explodedBombs.size())
	{
	  delete this->_gameManager._match._explodedBombs.back();
	  this->_gameManager._match._explodedBombs.pop_back();
	}
    }
}
