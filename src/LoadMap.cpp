/*
 * NicoW
 * 28.12.05
 */

#include <iostream>		// REMOVE
#include "LoadMap.hpp"

LoadMap::LoadMap(GameManager& game, std::vector<Map *> & map)
  : AMenu("menu/Background2.png", "menu/Background2.png", 1600.0f, -1.0f, 3600.0f, game),
    _map(map)
{
  bool					selected = true;
  std::vector<Map *>::const_iterator	it = map.begin();
  double				yTag = 4050.0f;
  int					i = 0;
  int					yText = 400;

  for (; it != map.end() ; ++it)
    {
      this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", selected, false, TokenMenu::CREATEGAME, 2400.0f, 0.0f, yTag));
      this->_tags[i]->createText((*it)->getName(), 20, 800, yText);

      i++;
      yTag += 50.0;
      yText += 50;
      if (selected)
	selected = false;
    }
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAP, 2400.0f, 0.0f, yTag));
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
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      this->_gameManager._originMap = this->_map[this->_cursor];
      this->_gameManager._match._map = new Map(this->_map[this->_cursor]->getX(), 
					       this->_map[this->_cursor]->getY(),
					       this->_map[this->_cursor]->getMap());  
    }
}
