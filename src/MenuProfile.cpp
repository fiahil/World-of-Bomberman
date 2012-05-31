/*
 * lemonn_v
 * 15.05.12
 */

#include "MenuProfile.hpp"

MenuProfile::MenuProfile(GameManager& game)
  : AMenu("menu/background/backgroundGameMenu.jpg", "menu/background/backgroundGameMenu.jpg", 1600.0f, -1.0f, 800.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/NewGameNormal.png", "menu/tags/NewGameHighlit.png", true, false, TokenMenu::GAMECHOOSE, 2029.0f, 0.0f, 1050.0f));
  this->_tags.push_back(new Tag("menu/tags/LoadGameNormal.png", "menu/tags/LoadGameHighlit.png", false, false, TokenMenu::LOADSAVE, 2029.0f, 0.0f, 1115.0f));
  this->_tags.push_back(new Tag("menu/tags/SettingsNormal.png", "menu/tags/SettingsHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 2029.0f, 0.0f, 1180.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::MAINMENU, 2029.0f, 0.0f, 1245.0f));
  this->_tags.push_back(new Tag("menu/tags/QuitNormal.png", "menu/tags/QuitHighlit.png", false, false, TokenMenu::QUIT, 2029.0f, 0.0f, 1310.0f));
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
