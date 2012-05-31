/*
 * NicoW
 * 27.05.12
 */

#include "MenuMap.hpp"

MenuMap::MenuMap(GameManager& game)
  : AMenu("menu/background/backgroundMap.jpg", "menu/background/backgroundMap.jpg", 0.0f, -1.0f, 3200.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/RandomNormal.png", "menu/tags/RandomHighlit.png", true, false, TokenMenu::CREATEGAME, 429.0f, 0.0f, 3600.0f));
  this->_tags.push_back(new Tag("menu/tags/LoadMapNormal.png", "menu/tags/LoadMapHighlit.png", false, false, TokenMenu::LOADMAP, 429.0f, 0.0f, 3665.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::IA, 429.0f, 0.0f, 3730.0f));
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
  return (3600.0f);
}

void		MenuMap::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      int	size =
	((this->_gameManager._nbPlayers *  this->_gameManager._nbTeams) + 2) * 2;

      if (size < 10)
	size = 10;
      this->_gameManager._match._map = new Map(size, size, 2, 2);
      this->_gameManager._originMap = new Map(this->_gameManager._match._map->getX(),
					      this->_gameManager._match._map->getY(),
					      this->_gameManager._match._map->getMap());
    }
}

