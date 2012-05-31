/*
 * NicoW
 * 27.05.12
 */

#include "MenuIA.hpp"

MenuIA::MenuIA(GameManager& game)
  : AMenu("menu/background/backgroundAI.jpg", "menu/background/backgroundAI.jpg", 1600.0f, -1.0f, 2700.0f, game)
{
  this->_tags.push_back(new Tag("menu/EasyNormal.png", "menu/EasyHighlit.png", true, false, TokenMenu::TEAM, 2400.0f, 0.0f, 2900.0f));
  this->_tags.push_back(new Tag("menu/NormalNormal.png", "menu/NormalHighlit.png", false, false, TokenMenu::TEAM, 2400.0f, 0.0f, 2950.0f));
  this->_tags.push_back(new Tag("menu/HardNormal.png", "menu/HardHighlit.png", false, false, TokenMenu::TEAM, 2400.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::GAMECHOOSE, 2400.0f, 0.0f, 3050.0f));
}

MenuIA::~MenuIA(void)
{
}

double		MenuIA::getCenterX(void) const
{
  return (2400.0f);
}

double		MenuIA::getCenterY(void) const
{
  return (3150.0f);
}

void		MenuIA::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::TEAM)
    {
      if (this->_cursor == 0)
  	this->_gameManager._typeAI = AIType::EASY;
      else if (this->_cursor == 1)
  	this->_gameManager._typeAI = AIType::NORMAL;
      else if (this->_cursor == 2)
  	this->_gameManager._typeAI = AIType::HARD;
    }
}
