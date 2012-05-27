/*
 * lemonn_v
 * 15.05.12
 */

#include "MainMenu.hpp"

MainMenu::MainMenu(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 0.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/NewProfileNormal.png", "menu/NewProfileHighlit.png", true, false, TokenMenu::NEWPROFILE, 790.0f, 0.0f, 390.0f));
  this->_tags.push_back(new Tag("menu/LoadProfileNormal.png", "menu/LoadProfileHighlit.png", false, false, TokenMenu::LOADPROFILE, 790.0f, 0.0f, 430.0f));
  this->_tags.push_back(new Tag("menu/QuitNormal.png", "menu/QuitHighlit.png", false, false, TokenMenu::QUIT, 790.0f, 0.0f, 480.0f));
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
