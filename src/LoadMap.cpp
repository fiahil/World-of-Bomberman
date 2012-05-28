/*
 * NicoW
 * 28.12.05
 */

#include "LoadMap.hpp"

LoadMap::LoadMap(GameManager& game, const std::vector<Map *> & /* map */)
  : AMenu("menu/Background2.png", "menu/Background2.png", 1600.0f, -1.0f, 3600.0f, game)
{
  // std::vector<Map *>::const_iterator	it = map.begin();

  // for (; it != map.end ; ++it)
  //   {
  //     this->_tags.push_back(new Tag("menu/NewProfileNormal.png", "menu/NewProfileHighlit.png", true, false, TokenMenu::NEWPROFILE, 800.0f, 0.0f, 450.0f));
  //   }
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
