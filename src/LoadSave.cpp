/*
 * NicoW
 * 27.05.12
 */

#include "LoadSave.hpp"

LoadSave::LoadSave(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background2.png", 3200.0f, -1.0f, 900.0f, game)
{
}

LoadSave::~LoadSave(void)
{
}

double		LoadSave::getCenterX(void) const
{
  return (4000.0f);
}

double		LoadSave::getCenterY(void) const
{
  return (1350.0f);
}

void		LoadSave::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}
