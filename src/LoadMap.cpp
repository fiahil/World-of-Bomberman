/*
 * NicoW
 * 28.12.05
 */

#include <iostream>		// REMOVE
#include "LoadMap.hpp"

LoadMap::LoadMap(GameManager& game, std::vector<Map *> & map)
  : AMenu("menu/background/backgroundLoadMap.jpg", "menu/background/backgroundLoadMap.jpg", 1600.0f, -1.0f, 3200.0f, game),
    _map(map),
    _timerL(-1.0f),
    _timerR(-1.0f),
    _index(0)
{
  this->_tags.push_back(new Tag("menu/tags/LoadNormal.png", "menu/tags/LoadHighlit.png", true, false, TokenMenu::LAST, 2029.0f, 0.0f, 3550.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::CREATEGAME, 2029.0f, 0.0f, 3665.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::MAP, 2029.0f, 0.0f, 3730.0f));
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
  return (3600.0f);
}

void		LoadMap::updateText() const
{
  if (this->_map.size())
    {
      this->_tags[0]->createText(this->_map[this->_index]->getName(), 20, 800, 365);
      this->_tags[1]->createText("info", 20, 500, 414);
    }
  else
    {
      this->_tags[0]->createText("", 20, 800, 365);
      this->_tags[1]->createText("", 20, 500, 414);
    }
}

void		LoadMap::changeMap(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_index;
      if (static_cast<int>(this->_index) < 0)
	this->_index = this->_map.size() - 1;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_index;
      if (this->_index >= this->_map.size())
	this->_index = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void		LoadMap::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 0)
    this->changeMap(clock, input);
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      this->_gameManager._originMap = this->_map[this->_cursor];
      this->_gameManager._match._map = new Map(this->_map[this->_cursor]->getX(),
					       this->_map[this->_cursor]->getY(),
					       this->_map[this->_cursor]->getMap());
    }
}
