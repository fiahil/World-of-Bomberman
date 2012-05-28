/*
 * Texan
 * 27.05.12
 */

#include <algorithm>
#include <iostream>
#include "LoadProfile.hpp"

LoadProfile::LoadProfile(GameManager& game, std::vector<Profile *>& profiles)
  : AMenu("menu/Background3.png", "menu/Background3.png", 0.0f, -1.0f, 900.0f, game)
{
  profiles = this->_profileLoader.getProfiles();

  /*
    One tag per profile available.
    gotta see how to display with scrolling
  */

  unsigned int	i;
  for (i = 0; i < profiles.size(); ++i)
    {
      if (!i)
	this->_tags.push_back(new Tag("menu/BlankNormal.png", "menu/BlankHighlit.png", true, false, TokenMenu::PROFILE, 800.0f, 0.0f, 1000.0f));
      else
	this->_tags.push_back(new Tag("menu/BlankNormal.png", "menu/BlankHighlit.png", false, false, TokenMenu::PROFILE, 800.0f, 0.0f, (1000.0f + (50.0f * i))));
      this->_tags.back()->setTextDraw(true);
      this->_tags.back()->createText(profiles[i]->getName(), 30.0f, 830.0f, (65.0f + (45.0f * i)));
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

static bool	isSelected(Tag *obj)
{
  return (obj->getStatus());
}

int	LoadProfile::getCurTagPos(void) const
{
  unsigned int	i;

  for (i = 0; !isSelected(this->_tags[i]); ++i);
  return (i);
}

void	LoadProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if ((this->_curToken != TokenMenu::LAST) && (this->getCurTagPos() < (this->_tags.size() - 1)))
    this->_gameManager._mainProfile = this->_profileLoader.getProfiles()[this->getCurTagPos()];
}
