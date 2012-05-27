/*
 * NicoW
 * 27.05.12
 */

#include "MenuMap.hpp"

MenuMap::MenuMap(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 0.0f, -1.0f, 3600.0f, game)
{
  this->_tags.push_back(new Tag("menu/RandomNormal.png", "menu/RandomHighlit.png", true, false, /**/TokenMenu::MAP, 800.0f, 0.0f, 3800.0f));
  this->_tags.push_back(new Tag("menu/LoadNormal.png", "menu/LoadHighlit.png", false, false, /**/TokenMenu::MAP, 800.0f, 0.0f, 3850.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, /**/TokenMenu::MAINMENU, 800.0f, 0.0f, 3900.0f));
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

void		MenuMap::doAction(gdl::GameClock const&, gdl::Input&)
{
}
