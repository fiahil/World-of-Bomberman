/*
 * lemonn_v
 * 15.05.12
 */

#include "MenuProfile.hpp"

MenuProfile::MenuProfile(GameManager& game)
  : AMenu("menu/background/backgroundGameMenu.jpg", "menu/background/backgroundGameMenu.jpg",
	  1600.0f, -1.0f, 800.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/NewGameNormal.png", "menu/tags/NewGameHighlit.png",
				true, false, TokenMenu::GAMECHOOSE, 2029.0f, 0.0f, 1000.0f));
  this->_tags.push_back(new Tag("menu/tags/LoadGameNormal.png", "menu/tags/LoadGameHighlit.png",
				false, false, TokenMenu::LOADSAVE, 2029.0f, 0.0f, 1065.0f));
  this->_tags.push_back(new Tag("menu/tags/SettingsNormal.png", "menu/tags/SettingsHighlit.png",
				false, false, TokenMenu::SETTINGSCHOOSE, 2029.0f, 0.0f, 1130.0f));
  this->_tags.push_back(new Tag("menu/tags/StatNormal.png", "menu/tags/StatHighlit.png",
				false, false, TokenMenu::STATS, 2029.0f, 0.0f, 1195.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png",
				false, false, TokenMenu::MAINMENU, 2029.0f, 0.0f, 1260.0f));
  this->_tags.push_back(new Tag("menu/tags/QuitNormal.png", "menu/tags/QuitHighlit.png",
				false, false, TokenMenu::QUIT, 2029.0f, 0.0f, 1325.0f));
}

MenuProfile::~MenuProfile()
{
}

double		MenuProfile::getCenterX() const
{
  return 2400.0f;
}

double		MenuProfile::getCenterY() const
{
  return 1200.0f;
}

void		MenuProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (vKeyEvent::const_iterator it = this->_keyEvent.begin();
       it != this->_keyEvent.end(); ++it)
    if (input.isKeyDown(it->first))
      (this->*it->second)(clock);
}
