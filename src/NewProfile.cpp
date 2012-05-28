/*
 * Texan
 *
 */

#include "NewProfile.hpp"

NewProfile::NewProfile(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background2.png", 1600.0f, -1.0f, 0.0f, game)
{
  /*
    TextEdit, gotta see how to set it up
   */

  this->_tags.push_back(new Tag("menu/NameNormal.png", "menu/NameHighlit.png", false, false, TokenMenu::NEWPROFILE, 2400.0f, 0.0f, 400.0f));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::PROFILE, 2400.0f, 0.0f, 450.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 2400.0f, 0.0f, 500.0f));
}

NewProfile::~NewProfile(void)
{
}

double	NewProfile::getCenterX(void) const
{
  return (2400.0f);
}

double	NewProfile::getCenterY(void) const
{
  return (450.0f);
}

void	NewProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->_textEdit[0]->update(clock, input);
  /*for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
    (this->*_keyEvent[i].second)(clock);*/
}
