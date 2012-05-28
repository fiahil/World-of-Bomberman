/*
 * Texan
 * 27.05.2012
 */

#include "TeamMenu.hpp"

TeamMenu::TeamMenu(GameManager& game)
  : AMenu("menu/Background5.png", "menu/Background5.png", 0.0f, -1.0f, 2700.0f, game)
{
  //this->_tags.push_back(new Tag("NbTextNormal.png", "NbTextHighlit.png", false, ));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::MAP, 800.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 3100.0f));
}

TeamMenu::~TeamMenu()
{
}

double	TeamMenu::getCenterX(void) const
{
  return (800.0f);
}

double	TeamMenu::getCenterY(void) const
{
  return (3150.0f);
}

void	TeamMenu::doAction(gdl::GameClock const&, gdl::Input&)
{
}
