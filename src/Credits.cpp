/*
 * NicoW
 * 28.05.12
 */

#include "Credits.hpp"

Credits::Credits(GameManager& game)
  : AMenu("menu/Background10.png", "menu/Background10.png", -1600.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", true, false, TokenMenu::MAINMENU, -800.0f, 0.0f, 450.0f));
}

Credits::~Credits(void)
{
}

double		Credits::getCenterX(void) const
{
  return (-800.0f);
}

double		Credits::getCenterY(void) const
{
  return (450.0f);
}

void		Credits::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
