/*
 * lemonn_v
 * 15.05.12
 */

#include "MainMenu.hpp"

MainMenu::MainMenu(GameManager& game)
  : AMenu("Background.png", "Background.png", 0.0f, -1.0f, 0.0f, game)
{

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
