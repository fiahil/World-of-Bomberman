/*
 * NicoW
 * 29.05.12
 */

#include "SettingsChoose.hpp"

SettingsChoose::SettingsChoose(GameManager& game)
  : AMenu("menu/background/backgroundSettings.jpg", "menu/background/backgroundSettings.jpg",
	  1600.0f, -1.0f, 1600.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/CommandsNormal.png", "menu/tags/CommandsHighlit.png",
				false, false, TokenMenu::SETTINGS, 2029.0f, 0.0f, 2000.0f));
  this->_tags.push_back(new Tag("menu/tags/PersonalizationNormal.png", "menu/tags/PersonalizationHighlit.png",
				false, false, TokenMenu::SKINCHOOSE, 2029.0f, 0.0f, 2065.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png",
				false, false, TokenMenu::PROFILE, 2029.0f, 0.0f, 2130.0f));
}

SettingsChoose::~SettingsChoose()
{
}

double		SettingsChoose::getCenterX() const
{
  return 2400.0f;
}

double		SettingsChoose::getCenterY() const
{
  return 2000.0f;
}

void		SettingsChoose::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (vKeyEvent::const_iterator it = this->_keyEvent.begin();
       it != this->_keyEvent.end(); ++it)
    if (input.isKeyDown(it->first) ||
	JsManager::getMe()->isJsDown(JsMode::MENU, it->first))
      (this->*it->second)(clock);
}
