/*
 * NicoW
 * 29.05.12
 */

#include "SettingsChoose.hpp"

SettingsChoose::SettingsChoose(GameManager& game)
  : AMenu("menu/background/backgroundConfiguration.jpg", "menu/background/backgroundConfiguration.jpg", 1600.0f, -1.0f, 1600.0f, game)
{
  this->_tags.push_back(new Tag("menu/KeyboardNormal.png", "menu/KeyboardHighlit.png", false, false, TokenMenu::SETTINGS, 2400.0f, 0.0f, 2000.0f));
  this->_tags.push_back(new Tag("menu/SkinChooseNormal.png", "menu/SkinChooseHighlit.png", false, false, TokenMenu::SKINCHOOSE, 2400.0f, 0.0f, 2050.0f));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::PROFILE, 2400.0f, 0.0f, 2100.0f));
}

SettingsChoose::~SettingsChoose()
{
}

double	SettingsChoose::getCenterX() const
{
  return 2400.0f;
}

double	SettingsChoose::getCenterY() const
{
  return 2000.0f;
}

void	SettingsChoose::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
