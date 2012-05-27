/*
 * NicoW
 * 27.05.12
 */

#include "GameChoose.hpp"

GameChoose::GameChoose(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 0.0f, -1.0f, 1800.0f, game)
{
  this->_tags.push_back(new Tag("menu/SoloNormal.png", "menu/SoloHighlit.png", true, false, TokenMenu::IA, 800.0f, 0.0f, 2000.0f));
  this->_tags.push_back(new Tag("menu/CoopNormal.png", "menu/CoopHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 2050.0f));
  this->_tags.push_back(new Tag("menu/VersusNormal.png", "menu/VersusHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 2100.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::PROFILE, 800.0f, 0.0f, 2150.0f));
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
  return (2250.0f);
}

void		GameChoose::doAction(gdl::GameClock const&, gdl::Input&)
{
}
