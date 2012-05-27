/*
 * Texan
 * 25.05.2012
 */

#include <iostream>
#include <algorithm>
#include "DirWalker.hpp"
#include "MapManager.hpp"

MapManager::MapManager(void)
{
  this->setMaps();
}

void			MapManager::setMaps(void)
{
  std::cout << "Before" << std::endl;
  DirWalker	_texasRanger("./Ressources/saves/");
  std::cout << "After" << std::endl;

  while (!(_texasRanger.isEnd()))
    {
      this->_maps.push_back(this->getMap(*_texasRanger.current()));
      _texasRanger.clean();
      ++_texasRanger;
    }
}

Map*			MapManager::getMap(size_t idx)
{
  if (idx > this->_maps.size())
    return (0);
  return (this->_maps[idx]);
}

Map*			MapManager::getMap(const std::string& file)
{
  Map*	ret = new Map(file);

  /*
    Gerer exception ?
  */

  return (ret);
}

const std::vector<Map *>&	MapManager::getAll(void) const
{
  return (this->_maps);
}

static void		freeMap(Map *obj)
{
  if (obj)
    {
      delete (obj);
      obj = 0;
    }
}

void			MapManager::unsetMaps(void)
{
  for_each(this->_maps.begin(), this->_maps.end(), freeMap);
}
