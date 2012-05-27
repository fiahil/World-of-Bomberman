/*
 * Texan
 *
 */

#include "NewProfile.hpp"

NewProfile::NewProfile(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background2.png", 1650.0f, -1.0f, 0.0f, game)
{
  /*
    TextEdit, gotta see how to set it up
   */

  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::PROFILE, 2450.0f, 0.0f, 390.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 2450.0f, 0.0f, 430.0f));
}

NewProfile::~NewProfile(void)
{
}

double	NewProfile::getCenterX(void) const
{
  return (2450.0f);
}

double	NewProfile::getCenterY(void) const
{
  return (450.0f);
}
