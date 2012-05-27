/*
 * NicoW
 * 27.05.12
 */

#include "LoadSave.hpp"

LoadSave::LoadSave(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background.png", 0.0f, -1.0f, 900.0f, game)
{
}

LoadSave::~LoadSave(void)
{
}

double		LoadSave::getCenterX(void) const
{
  return (800.0f);
}

double		LoadSave::getCenterY(void) const
{
  return (1350.0f);
}

void		LoadSave::doAction(gdl::GameClock const&, gdl::Input&)
{
}
