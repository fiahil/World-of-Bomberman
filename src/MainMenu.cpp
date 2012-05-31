/*
 * lemonn_v
 * 15.05.12
 */

#include <iostream>
#include "MainMenu.hpp"

MainMenu::MainMenu(GameManager& game)
  : AMenu("menu/background/backgroundMainMenu.jpg", "menu/background/backgroundMainMenu.jpg", 0.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/NewProfileNormal.png", "menu/NewProfileHighlit.png", true, true, TokenMenu::NEWPROFILE, 800.0f, 0.0f, 450.0f));
  this->_tags.push_back(new Tag("menu/LoadProfileNormal.png", "menu/LoadProfileHighlit.png", false, true, TokenMenu::LOADPROFILE, 800.0f, 0.0f, 500.0f));
  this->_tags.push_back(new Tag("menu/CreditsNormal.png", "menu/CreditsHighlit.png", false, true, TokenMenu::CREDITS, 800.0f, 0.0f, 550.0f));
  this->_tags.push_back(new Tag("menu/QuitNormal.png", "menu/QuitHighlit.png", false, true, TokenMenu::QUIT, 800.0f, 0.0f, 600.0f));
}

MainMenu::~MainMenu()
{

}

double	MainMenu::getCenterX() const
{
  return 800.0f;
}

double	MainMenu::getCenterY() const
{
  return 450.0f;
}

void	MainMenu::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_gameManager._mainProfile)
    this->_gameManager._mainProfile = 0;
}
