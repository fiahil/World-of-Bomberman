/*
 * NicoW
 * 27.05.12
 */

#include "MenuIA.hpp"

MenuIA::MenuIA(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 1600.0f, -1.0f, 2700.0f, game)
{
  this->_tags.push_back(new Tag("menu/NbTextNormal.png", "menu/NbTextHighlit.png", true, false, /**/TokenMenu::IA, 2400.0f, 0.0f, 2900.0f));
  this->_tags.push_back(new Tag("menu/LevelNormal.png", "menu/LevelHighlit.png", false, false, /**/TokenMenu::IA, 2400.0f, 0.0f, 2950.0f));
  this->_tags.push_back(new Tag("menu/EasyNormal.png", "menu/EasyHighlit.png", false, false, /**/TokenMenu::MAP, 2400.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/NormalNormal.png", "menu/NormalHighlit.png", false, false, /**/TokenMenu::MAP, 2400.0f, 0.0f, 3050.0f));
  this->_tags.push_back(new Tag("menu/HardNormal.png", "menu/HardHighlit.png", false, false, /**/TokenMenu::MAP, 2400.0f, 0.0f, 3100.0f));
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

void		MenuIA::doAction(gdl::GameClock const&, gdl::Input&)
{
}
