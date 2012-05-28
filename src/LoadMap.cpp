/*
 * NicoW
 * 28.12.05
 */

#include "LoadMap.hpp"

LoadMap::LoadMap(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background.png", 1600.0f, -1.0f, 3600.0f, game)
{
}

LoadMap::~LoadMap(void)
{
}

double		LoadMap::getCenterX(void) const
{
  return (2400.0f);
}

double		LoadMap::getCenterY(void) const
{
  return (4050.0f);
}

void		LoadMap::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
