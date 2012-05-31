/*
 * lemonn_v
 * 15.05.12
 */

#include "MenuProfile.hpp"

MenuProfile::MenuProfile(GameManager& game)
  : AMenu("menu/background/backgroundGameMenu.jpg", "menu/background/backgroundGameMenu.jpg", 1600.0f, -1.0f, 800.0f, game)
{
  this->_tags.push_back(new Tag("menu/NewGameNormal.png", "menu/NewGameHighlit.png", true, false, TokenMenu::GAMECHOOSE, 2400.0f, 0.0f, 1200.0f));
  this->_tags.push_back(new Tag("menu/LoadGameNormal.png", "menu/LoadGameHighlit.png", false, false, TokenMenu::LOADSAVE, 2400.0f, 0.0f, 1250.0f));
  this->_tags.push_back(new Tag("menu/SettingsNormal.png", "menu/SettingsHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 2400.0f, 0.0f, 1300.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 2400.0f, 0.0f, 1350.0f));
  this->_tags.push_back(new Tag("menu/QuitNormal.png", "menu/QuitHighlit.png", false, false, TokenMenu::QUIT, 2400.0f, 0.0f, 1400.0f));
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
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
