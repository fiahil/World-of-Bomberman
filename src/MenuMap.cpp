/*
 * NicoW
 * 27.05.12
 */

#include "MenuMap.hpp"

MenuMap::MenuMap(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 0.0f, -1.0f, 3600.0f, game)
{
  this->_tags.push_back(new Tag("menu/RandomNormal.png", "menu/RandomHighlit.png", true, false, TokenMenu::CREATEGAME, 800.0f, 0.0f, 3800.0f));
  this->_tags.push_back(new Tag("menu/LoadNormal.png", "menu/LoadHighlit.png", false, false, TokenMenu::LOADMAP, 800.0f, 0.0f, 3850.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 3900.0f));
}

MenuMap::~MenuMap(void)
{
}

double		MenuMap::getCenterX(void) const
{
  return (800.0f);
}

double		MenuMap::getCenterY(void) const
{
  return (4050.0f);
}

void		MenuMap::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      int	size = this->_gameManager._match._players.size() * 3;

      if (size < 10)
	size = 10;
      this->_gameManager._match._map = new Map(size, size, 2, 2);
    }
}

