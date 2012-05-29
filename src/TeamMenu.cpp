/*
 * Texan
 * 27.05.2012
 */

#include "TeamMenu.hpp"

TeamMenu::TeamMenu(GameManager& game)
  : AMenu("menu/Background5.png", "menu/Background5.png", 0.0f, -1.0f, 2700.0f, game)
{
  this->_tags.push_back(new Tag("menu/NbPlayerNormal.png", "menu/NbPlayerHighlit.png", true, false, TokenMenu::MAP, 800.0f, 0.0f, 2900.0f));
  this->_tags.push_back(new Tag("menu/NbTeamNormal.png", "menu/NbTeamHighlit.png", false, false, TokenMenu::MAP, 800.0f, 0.0f, 2950.0f));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::MAP, 800.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 3050.0f));
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

void	TeamMenu::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}

