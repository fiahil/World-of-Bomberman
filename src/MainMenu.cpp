/*
 * lemonn_v
 * 15.05.12
 */

#include <iostream>
#include "MainMenu.hpp"

MainMenu::MainMenu(GameManager& game)
  : AMenu("menu/background/backgroundMainMenu.jpg", "menu/background/backgroundMainMenu.jpg", 0.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/NewProfileNormal.png", "menu/tags/NewProfileHighlit.png", true, true, TokenMenu::NEWPROFILE, 429.0f, 0.0f, 250.0f));
  this->_tags.push_back(new Tag("menu/tags/LoadProfileNormal.png", "menu/tags/LoadProfileHighlit.png", false, true, TokenMenu::LOADPROFILE, 429.0f, 0.0f, 315.0f));
  this->_tags.push_back(new Tag("menu/tags/CreditsNormal.png", "menu/tags/CreditsHighlit.png", false, true, TokenMenu::CREDITS, 429.0f, 0.0f, 380.0f));
  this->_tags.push_back(new Tag("menu/tags/QuitNormal.png", "menu/tags/QuitHighlit.png", false, true, TokenMenu::QUIT, 429.0f, 0.0f, 445.0f));
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
  return 400.0f;
}

void	MainMenu::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_gameManager._mainProfile)
    this->_gameManager._mainProfile = 0;
}
