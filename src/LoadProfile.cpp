/*
 * Texan
 * 27.05.12
 */

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

  unsigned int	i;
  for (i = 0; i < this->_profiles.size(); ++i)
    {
      if (!i)
	this->_tags.push_back(new Tag("menu/BlankNormal.png", "menu/BlankHighlit.png", true, false, TokenMenu::PROFILE, 800.0f, 0.0f, 1000.0f));
      else
	this->_tags.push_back(new Tag("menu/BlankNormal.png", "menu/BlankHighlit.png", false, false, TokenMenu::PROFILE, 800.0f, 0.0f, (1000.0f + (50.0f * i))));
      this->_tags.back()->setTextDraw(true);
      this->_tags.back()->createText(this->_profiles[i]->getName(), 30.0f, 830.0f, (65.0f + (45.0f * i)));
    }
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 800.0f, 0.0f, (1000.0f + (50.0f * i))));
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

void	LoadProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
