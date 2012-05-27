#include <iostream>
#include "LoadProfile.hpp"

LoadProfile::LoadProfile(GameManager& game)
  : AMenu("menu/Background3.png", "menu/Background3.png", 0.0f, -1.0f, 900.0f, game)
{
  this->_profiles = this->_profileLoader.getProfiles();

  /*
    One tag per profile available.
    gotta see how to display with scrolling
  */

  // this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 800.0f, 0.0f, 1100.0f));
}

LoadProfile::~LoadProfile(void)
{
}

double	LoadProfile::getCenterX() const
{
  return (800.0f);
}

double	LoadProfile::getCenterY() const
{
  return (1350.0f);
}

void		LoadProfile::doAction(gdl::GameClock const&, gdl::Input&)
{
}
